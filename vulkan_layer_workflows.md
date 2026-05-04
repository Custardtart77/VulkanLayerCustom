# Vulkan Layer 完整加载调用流程

以本项目的 `VK_LAYER_CUSTOM` 为例，从应用启动到 API 调用的全过程。

---

## 阶段一：发现 Layer

```
应用调用 vkEnumerateInstanceLayerProperties()
         │
         ▼
    Vulkan Loader
         │
         ├─ 桌面：扫描 /usr/share/vulkan/explicit_layer.d/*.json
         │        解析 VkLayer_custom.json → 得到 layer 名称 "VK_LAYER_custom"
         │        得到 library_path → "libVkLayer_custom.so"
         │
         └─ Android：扫描 /data/local/tmp/*.so 或 APK 内 lib/<abi>/
                  dlopen("libVkLayer_custom.so")
                  dlsym("vkEnumerateInstanceLayerProperties")
                  直接调用 → 得到 layer 名称 "VK_LAYER_CUSTOM"
         │
         ▼
   返回给应用：系统有 1 个 Layer，名称 VK_LAYER_CUSTOM
```

### 桌面 vs Android 发现机制对比

| | 桌面 (Linux/Windows/macOS) | Android |
|---|---|---|
| **发现方式** | Loader 搜索 `explicit_layer.d/` 等目录下的 JSON 清单 | Loader 通过系统属性或 APK 内路径查找 `.so` |
| **Layer 元信息** | 在 JSON 中声明（name、api_version 等） | 编译进 `.so` 本身，通过 `vkEnumerateInstanceLayerProperties` 返回 |
| **库路径** | JSON 中 `library_path` 指定 | 固定位置：`/data/local/tmp/` 或 APK 内 `lib/<abi>/` |
| **扩展信息** | JSON 中 `instance_extensions` / `device_extensions` | 通过 `vkEnumerateInstanceExtensionProperties` 返回 |

---

## 阶段二：激活 Layer

```
应用调用 vkCreateInstance(..., enabledLayerNames=["VK_LAYER_CUSTOM"])
         │
         ▼
    Vulkan Loader
         │
         │  ① dlopen("libVkLayer_custom.so")  （如果还没加载）
         │  ② dlsym("vkGetInstanceProcAddr")  → 拿到 GIPA
         │  ③ 构建 Layer 链：Loader → VK_LAYER_CUSTOM → Driver
         │     将链信息写入 pCreateInfo->pNext 链表：
         │       VkLayerInstanceCreateInfo {
         │         sType = VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO
         │         function = VK_LAYER_LINK_INFO
         │         u.pLayerInfo → {
         │           pfnNextGetInstanceProcAddr → Driver 的 GIPA
         │           pNext = nullptr (或下一个 Layer)
         │         }
         │       }
         │
         ▼
   调用 Layer 的 vkGetInstanceProcAddr(NULL, "vkCreateInstance")
         │
         ▼
   返回本层实现的 vkCreateInstance 函数指针
```

---

## 阶段三：vkCreateInstance — Layer 入链

```
Loader 调用 Layer 的 vkCreateInstance(pCreateInfo, pAllocator, &instance)
         │
         ▼  ┌─────────────────────────────────────────────────┐
            │  api_hook_handwritten_functions.h:32-69          │
            │                                                  │
            │  ① get_chain_info(pCreateInfo, VK_LAYER_LINK_INFO)
            │     → 从 pCreateInfo->pNext 链中找到链信息        │
            │                                                  │
            │  ② 从链信息获取下一层的 GIPA：                     │
            │     fpGetInstanceProcAddr = chain_info->u.pLayerInfo
            │                              ->pfnNextGetInstanceProcAddr
            │                                                  │
            │  ③ 获取下一层的 vkCreateInstance：                 │
            │     fpCreateInstance = fpGetInstanceProcAddr(NULL,
            │                                   "vkCreateInstance")
            │                                                  │
            │  ④ 链指针前移（关键！）：                          │
            │     chain_info->u.pLayerInfo = pLayerInfo->pNext  │
            │     ↑ 让下一层也用同样的逻辑继续往下走              │
            │                                                  │
            │  ⑤ 调用下一层的 vkCreateInstance：                 │
            │     fpCreateInstance(pCreateInfo, pAllocator, &instance)
            │                                                  │
            │  ⑥ 创建成功后，初始化本层的 Instance Dispatch Table：
            │     initInstanceTable(instance, fpGetInstanceProcAddr)
            │     → 用下一层的 GIPA 填充所有函数指针             │
            │     → 后续所有调用都能通过此表转发到下一层           │
            └─────────────────────────────────────────────────┘
         │
         ▼
   返回 VK_SUCCESS，Instance 创建完成
```

---

## 阶段四：vkCreateDevice — 同理入链

```
应用调用 vkCreateDevice(physicalDevice, pCreateInfo, ...)
         │
         ▼
    Loader → 调用 Layer 的 GIPA 查 "vkCreateDevice"
         │
         ▼
    Layer 的 vkCreateDevice()  ┌──────────────────────────────────────┐
                               │  api_hook_handwritten_functions.h:72  │
                               │                                       │
                               │  ① get_chain_info → 获取链信息        │
                               │  ② 获取下一层 GIPA + GDPA             │
                               │  ③ chain_info 前移                    │
                               │  ④ 调用下一层 vkCreateDevice          │
                               │  ⑤ initDeviceTable(device, GDPA)     │
                               │     → 填充 Device Dispatch Table     │
                               └──────────────────────────────────────┘
         │
         ▼
   Device 创建完成，Layer 链就绪
```

---

## 阶段五：运行时 API 调用 — 拦截与透传

以 `vkQueueSubmit` 为例：

```
应用调用 vkQueueSubmit(queue, ...)
         │
         ▼
    Loader 的 dispatch table → 指向 Layer 的 vkQueueSubmit
         │
         ▼  ┌──────────────────────────────────────────────┐
            │  generated/api_hook_dispatch.h 中生成的函数：   │
            │                                               │
            │  vkQueueSubmit(queue, submitCount, ...) {     │
            │      // pad: mutex（可加锁）                    │
            │      // 【这里插入你的自定义逻辑】               │
            │      auto result =                            │
            │        device_dispatch_table(queue)           │
            │          ->QueueSubmit(queue, submitCount,...)│
            │      // 【这里也可以后处理】                    │
            │      return result;                           │
            │  }                                            │
            └──────────────────────────────────────────────┘
         │
         ▼
   device_dispatch_table(queue)->QueueSubmit → 调用下一层（Driver）
         │
         ▼
   Driver 执行实际操作，结果逐层返回
```

---

## 四个必须导出的入口函数

| 函数 | 调用时机 | 作用 |
|------|---------|------|
| `vkEnumerateInstanceLayerProperties` | Instance 创建前，不需要任何 Vulkan 对象 | 声明 Layer 身份（名称、版本、描述） |
| `vkEnumerateInstanceExtensionProperties` | Instance 创建前，不需要任何 Vulkan 对象 | 声明 Layer 提供的扩展 |
| `vkGetInstanceProcAddr` | Instance 创建后 | 查询/分发所有 Instance + Device 级函数指针 |
| `vkGetDeviceProcAddr` | Device 创建后 | 查询/分发 Device 级函数指针（性能更优，直接调用） |

### 导出机制

- **Windows**：通过 `VkLayer_custom.def` 文件显式导出
- **Linux/macOS/Android**：通过 `EXPORT_FUNCTION` 宏（`__attribute__((visibility("default")))`）导出

---

## Dispatch Table 机制

`vk_layer_table.h/cpp` 实现了 Layer 的分发表，是调用转发的核心数据结构：

| 组件 | 作用 |
|------|------|
| `VkuInstanceDispatchTable` | 存储所有 Instance 级 Vulkan 函数指针 |
| `VkuDeviceDispatchTable` | 存储所有 Device 级 Vulkan 函数指针 |
| `initInstanceTable()` | 通过下一层 GIPA 初始化 Instance 分发表 |
| `initDeviceTable()` | 通过下一层 GDPA 初始化 Device 分发表 |
| `get_dispatch_key()` | 从 dispatchable object 首字段提取 key，区分不同 Instance/Device |
| `tableMap` / `tableInstanceMap` | 全局 map，dispatch key → dispatch table 映射 |

### GIPA vs GDPA 的区别

- **GIPA** (`vkGetInstanceProcAddr`)：可以查询所有函数（Instance + Device），但 Device 函数可能多一层间接调用开销
- **GDPA** (`vkGetDeviceProcAddr`)：只能查询 Device 级函数，但获取的函数指针可直接调用，无需经过 dispatch table 间接跳转，性能更优

---

## 完整调用链全景

```
应用
 │
 │  vkQueueSubmit(queue, ...)
 ▼
Loader (dispatch table 指向 Layer)
 │
 ▼
VK_LAYER_CUSTOM
 │  ├─ 拦截：可在此加自定义逻辑（日志、修改参数等）
 │  │
 │  ├─ device_dispatch_table(queue)->QueueSubmit(...)
 │  │  └─ 查表：dispatch key = *(void**)queue → 找到对应的 Device Dispatch Table
 │  │     └─ 表中 QueueSubmit 指针 → 指向下一层（Driver）的函数
 │  │
 │  ▼
Driver (真正执行硬件操作)
 │
 ▼
  返回结果沿原路返回：Driver → Layer → Loader → 应用
```

---

## 总结

**发现靠枚举函数（或 JSON），入链靠 `vkCreateInstance/vkCreateDevice` 中操作 `pNext` 链表，分发靠 GIPA/GDPA 返回 hook 函数指针，转发靠 Dispatch Table 存储的下一层函数指针。** 四个阶段环环相扣，使得 Layer 像一个"透明中间人"插入在应用和驱动之间。
