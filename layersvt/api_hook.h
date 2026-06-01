/* Copyright (c) 2015-2026 The Khronos Group Inc.
 * Copyright (c) 2015-2026 Valve Corporation
 * Copyright (c) 2015-2026 LunarG, Inc.
 * Copyright (C) 2015-2016 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Lenny Komow <lenny@lunarg.com>
 * Author: Shannon McPherson <shannon@lunarg.com>
 * Author: David Pinedo <david@lunarg.com>
 * Author: Charles Giessen <charles@lunarg.com>
 */

#pragma once

#define VK_NO_PROTOTYPES

#include "vulkan/vk_layer.h"
#include "vk_layer_table.h"
#include <vulkan/utility/vk_dispatch_table.h>

#include <vulkan/layer/vk_layer_settings.hpp>

// Include the video headers so we can print types that come from them
#include "vk_video/vulkan_video_codecs_common.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codec_av1std.h"
#include "vk_video/vulkan_video_codec_av1std_decode.h"

#include <string.h>
#include <stdint.h>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <fstream>
#include <mutex>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <map>
#include <set>
#include <thread>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <utility>

// ImGui Vulkan backend
#include "imgui/imgui.h"
#include "imgui/imgui_impl_vulkan.h"

#if defined(_WIN32) && !defined(NDEBUG)
#include <crtdbg.h>
#endif

#ifdef ANDROID
#include <memory>
#include <string_view>

#include <android/log.h>
#include <sys/system_properties.h>
// Disable warning about bitshift precedence
#pragma GCC diagnostic ignored "-Wshift-op-parentheses"

#define LOG_TAG "LayerCustom"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)


inline std::string ApiHookAndroidGetProcessPackageName() {
    std::ifstream cmdline("/proc/self/cmdline");
    if (!cmdline) {
        return {};
    }
    std::string name;
    std::getline(cmdline, name, '\0');
    return name;
}

#endif  // ANDROID

#if defined(__GNUC__) && __GNUC__ >= 4
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define EXPORT_FUNCTION __attribute__((visibility("default")))
#else
#define EXPORT_FUNCTION
#endif

#if defined(WIN32)
// Disable warning about bitshift precedence
#pragma warning(disable : 4554)
#endif



extern "C" {
// Forward declarations for dispatch
EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance instance, const char *pName);
EXPORT_FUNCTION VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice device, const char *pName);
}

#define MAX_STRING_LENGTH 1024

// We want to dump all extensions even beta extensions.
#ifndef VK_ENABLE_BETA_EXTENSIONS
#error "VK_ENABLE_BETA_EXTENSIONS not defined!"
#endif

// Ensure we are properly setting VK_USE_PLATFORM_METAL_EXT, VK_USE_PLATFORM_IOS_MVK, and VK_USE_PLATFORM_MACOS_MVK.
#if __APPLE__

// TODO: Add Metal support
// #ifndef VK_USE_PLATFORM_METAL_EXT
// #error "VK_USE_PLATFORM_METAL_EXT not defined!"
// #endif

#include <TargetConditionals.h>

#if TARGET_OS_IOS

#ifndef VK_USE_PLATFORM_IOS_MVK
#error "VK_USE_PLATFORM_IOS_MVK not defined!"
#endif

#endif  //  TARGET_OS_IOS

#if TARGET_OS_OSX

#ifndef VK_USE_PLATFORM_MACOS_MVK
#error "VK_USE_PLATFORM_MACOS_MVK not defined!"
#endif

#endif  // TARGET_OS_OSX

#endif  // __APPLE__

#if defined(VK_USE_64_BIT_PTR_DEFINES) && VK_USE_64_BIT_PTR_DEFINES == 1
#define TYPE_ERASE_HANDLE(handle) static_cast<void *>(handle)
#else
#define TYPE_ERASE_HANDLE(handle) static_cast<uint64_t>(handle)
#endif


static const char *GetDefaultPrefix() {
#ifdef __ANDROID__
    return "apihook";
#else
    return "APIHOOK";
#endif
}


class SwapchainRenderData {
   public:
    std::vector<VkImage> image;
    std::vector<VkImageView> image_view;
    std::vector<VkFramebuffer> framebuffer;

    VkSwapchainKHR swapchain;
    VkDevice device;
    VkRenderPass render_pass;
    uint32_t image_count;

    std::vector<VkCommandBuffer> command_buffer;
    std::vector<VkFence> fence;

    std::vector<VkSemaphore> render_finished_semaphore;


    SwapchainRenderData(VkDevice device, VkSwapchainKHR swapchain, const VkSwapchainCreateInfoKHR* pCreateInfo) {
        this->device = device;
        this->swapchain = swapchain;
    }
};

class DeviceRenderData {
   public:
    VkDevice device;
    VkPhysicalDevice physical_device;
    std::unordered_map<VkQueue, uint32_t> queue_family_index_map;

    VkCommandPool command_pool;
    VkDescriptorPool descriptor_pool;

    std::unordered_map<VkSwapchainKHR, SwapchainRenderData*> swapchain_render_data_map;

    DeviceRenderData(VkPhysicalDevice physicalDevice, VkDevice device) : physical_device(physicalDevice), device(device) {
        swapchain_render_data_map.clear();

    }

    void AddQueue(VkQueue queue, uint32_t queue_family_index) {
        if (queue_family_index_map.count(queue) < 1) {
            queue_family_index_map[queue] = queue_family_index;
        }
    }

    bool HasQueue(VkQueue queue) const {
        return queue_family_index_map.count(queue) > 0;
    }   
};

class ApiHookSettings {
   public:
    ApiHookSettings() {

    }

    ~ApiHookSettings() {
    }

    void init(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator) {
        VkuLayerSettingSet layerSettingSet = VK_NULL_HANDLE;
        vkuCreateLayerSettingSet("VK_LAYER_CUSTOM", vkuFindLayerSettingsCreateInfo(pCreateInfo), pAllocator, nullptr,
                                 &layerSettingSet);

        vkuSetLayerSettingCompatibilityNamespace(layerSettingSet, GetDefaultPrefix());

        // Read the format type first as it may be used in the output file extension
        /*
        output_format = ApiDumpFormat::Text;
        if (vkuHasLayerSetting(layerSettingSet, kSettingsKeyOutputFormat)) {
            std::string value;
            vkuGetLayerSettingValue(layerSettingSet, kSettingsKeyOutputFormat, value);
            value = ToLowerString(value);
            if (value == "html") {
                output_format = ApiDumpFormat::Html;
            } else if (value == "json") {
                output_format = ApiDumpFormat::Json;
            } else {
                output_format = ApiDumpFormat::Text;
            }
        }*/

        vkuDestroyLayerSettingSet(layerSettingSet, pAllocator);
    }

   private:
    // Utility member to enable easier comparison by forcing a string to all lower-case
    static std::string ToLowerString(const std::string &value) {
        std::string lower_value = value;
        std::transform(lower_value.begin(), lower_value.end(), lower_value.begin(), ::tolower);
        return lower_value;
    }

    // The mutable is necessary because everyone who 'writes' to the stream necessarily must be able to modify it.
    // Since basically every function in this struct is const, we have to work around that.
    std::ofstream output_file_stream;

    bool use_conditional_output = false;

    int tab_size;  // equal to the indent size if using spaces, otherwise is equal to 1
};

class ApiHookInstance {
   public:
    ApiHookInstance() noexcept : frame_count(0) { program_start = std::chrono::system_clock::now(); }
    // Can't copy or move this type
    ApiHookInstance(const ApiHookInstance &) = delete;
    ApiHookInstance &operator=(const ApiHookInstance &) = delete;
    ApiHookInstance(ApiHookInstance &&) = delete;
    ApiHookInstance &operator=(ApiHookInstance &&) = delete;

    ~ApiHookInstance() {
    }

    void initLayerSettings(const VkInstanceCreateInfo *pCreateInfo, const VkAllocationCallbacks *pAllocator) {
        this->hook_settings.init(pCreateInfo, pAllocator);

#ifdef __ANDROID__
        if (!out_file.is_open()) {
            std::string pkg = ApiHookAndroidGetProcessPackageName();
            if (pkg.empty()) {
                pkg = "unknown";
            }
            const std::string path = "/sdcard/Android/data/" + pkg + "/files/LayerCustom.txt";
            out_file.open(path, std::ios::out | std::ios::trunc);
            if (out_file.fail()) {
                LOGD("could not open the file! path=%s", path.c_str());
            } else {
                LOGD("open the file! path=%s", path.c_str());
                out_file << "LayerCustom.txt Create Success." << std::endl;
            }
        }
#endif
    }
    std::ofstream &outfile() { return out_file; }

    std::mutex &outputMutex() { return output_mutex; }

    ApiHookSettings &settings() { return hook_settings; }


    VkCommandBufferLevel getCmdBufferLevel() {
        std::lock_guard<std::mutex> lg(cmd_buffer_state_mutex);
        const auto level_iter = cmd_buffer_level.find(cmd_buffer);
        assert(level_iter != cmd_buffer_level.end());
        const auto level = level_iter->second;
        return level;
    }

    void eraseCmdBuffers(VkDevice device, VkCommandPool cmd_pool, std::vector<VkCommandBuffer> cmd_buffers) {
        cmd_buffers.erase(std::remove(cmd_buffers.begin(), cmd_buffers.end(), nullptr), cmd_buffers.end());
        if (!cmd_buffers.empty()) {
            std::lock_guard<std::mutex> lg(cmd_buffer_state_mutex);

            const auto pool_cmd_buffers_iter = cmd_buffer_pools.find(std::make_pair(device, cmd_pool));
            assert(pool_cmd_buffers_iter != cmd_buffer_pools.end());

            for (const auto cmd_buffer : cmd_buffers) {
                pool_cmd_buffers_iter->second.erase(cmd_buffer);

                assert(cmd_buffer_level.count(cmd_buffer) > 0);
                cmd_buffer_level.erase(cmd_buffer);
            }
        }
    }

    void addCmdBuffers(VkDevice device, VkCommandPool cmd_pool, std::vector<VkCommandBuffer> cmd_buffers,
                       VkCommandBufferLevel level) {
        std::lock_guard<std::mutex> lg(cmd_buffer_state_mutex);
        auto &pool_cmd_buffers = cmd_buffer_pools[std::make_pair(device, cmd_pool)];
        pool_cmd_buffers.insert(cmd_buffers.begin(), cmd_buffers.end());

        for (const auto cmd_buffer : cmd_buffers) {
            assert(cmd_buffer_level.count(cmd_buffer) == 0);
            cmd_buffer_level[cmd_buffer] = level;
        }
    }

    void eraseCmdBufferPool(VkDevice device, VkCommandPool cmd_pool) {
        if (cmd_pool != VK_NULL_HANDLE) {
            std::lock_guard<std::mutex> lg(cmd_buffer_state_mutex);

            const auto cmd_buffers_iter = cmd_buffer_pools.find(std::make_pair(device, cmd_pool));
            if (cmd_buffers_iter != cmd_buffer_pools.end()) {
                for (const auto cmd_buffer : cmd_buffers_iter->second) {
                    assert(cmd_buffer_level.count(cmd_buffer) > 0);
                    cmd_buffer_level.erase(cmd_buffer);
                }
                cmd_buffers_iter->second.clear();
            }
        }
    }
    



    static ApiHookInstance &current() {
        // Because ApiHookInstance is a static variable in a static function, there will only be one instance of it.
        // Additionally, the object will be constructed on the *first* call to current(), rather than at process startup time.
        static ApiHookInstance current_instance;
        return current_instance;
    }

    std::unordered_map<uint64_t, std::string> object_name_map;

    void set_vk_instance(VkPhysicalDevice phys_dev, VkInstance instance) { vk_instance_map.insert({phys_dev, instance}); }
    VkInstance get_vk_instance(VkPhysicalDevice phys_dev) const {
        if (vk_instance_map.count(phys_dev) == 0) return VK_NULL_HANDLE;
        return vk_instance_map.at(phys_dev);
    }

    // --- ImGui Vulkan 初始化 ---
    // 在 vkCreateDevice 之后调用，使用 hook 捕获的 Vulkan 资源
    void InitImGuiVulkan(VkInstance instance, VkPhysicalDevice physicalDevice, VkDevice device,
                         uint32_t queueFamilyIndex, VkQueue queue) {
        if (is_imgui_init) return;

        // 创建 ImGui 上下文
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename = nullptr;  // 不保存/加载 ini 文件

        // 对于没有窗口系统的 Layer hook，不需要 Platform Backend
        // 直接设置 display size 为一个默认值（后续可以通过 hook swapchain 信息来更新）
        io.DisplaySize = ImVec2(1920, 1080);

        // 由于项目定义了 VK_NO_PROTOTYPES，需要先加载 Vulkan 函数指针
        // 使用 layer 内部的 instance dispatch table 来获取函数指针
        uint32_t api_version = VK_API_VERSION_1_3;
        auto inst_disp = instance_dispatch_table(instance);
        ImGui_ImplVulkan_LoadFunctions(api_version,
            [](const char* function_name, void* user_data) {
                auto* table = static_cast<VkuInstanceDispatchTable*>(user_data);
                return table->GetInstanceProcAddr(VK_NULL_HANDLE, function_name);
            },
            inst_disp);

        // 初始化 Vulkan 渲染后端
        ImGui_ImplVulkan_InitInfo init_info = {};
        init_info.Instance = instance;
        init_info.PhysicalDevice = physicalDevice;
        init_info.Device = device;
        init_info.QueueFamily = queueFamilyIndex;
        init_info.Queue = queue;
        //init_info.ApiVersion = VK_API_VERSION_1_3;              // Pass in your value of VkApplicationInfo::apiVersion, otherwise will default to header version.

        init_info.PipelineCache = nullptr;
        // init_info.DescriptorPool = g_DescriptorPool;
        // init_info.MinImageCount = g_MinImageCount;
        init_info.ImageCount = 2;
        init_info.Allocator = nullptr;
        init_info.PipelineInfoMain.RenderPass = nullptr;
        init_info.PipelineInfoMain.Subpass = 0;
        init_info.PipelineInfoMain.MSAASamples = VK_SAMPLE_COUNT_1_BIT;
        //init_info.CheckVkResultFn = check_vk_result;

        if (!ImGui_ImplVulkan_Init(&init_info)) {
            return;
        }

        is_imgui_init = true;
  
    }

    // 关闭 ImGui
    void ShutdownImGuiVulkan() {
        if (is_imgui_init) {
            ImGui_ImplVulkan_Shutdown();
            ImGui::DestroyContext();
            is_imgui_init = false;
        }
    }

    void Render(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
        if (!is_imgui_init) return;


        // 开始新帧
        /*
        ImGui_ImplVulkan_NewFrame();
        ImGui::NewFrame();

        // 你的 UI 内容
        ImGui::Begin("LayerCustom");
        ImGui::Text("Hello, Vulkan Layer!");
        ImGui::Text("Frame: %llu", static_cast<unsigned long long>(frame_count));
        ImGui::End();

        // 渲染
        ImGui::Render();
        ImDrawData* draw_data = ImGui::GetDrawData();
        if (draw_data) {
            ImGui_ImplVulkan_RenderDrawData(draw_data, commandBuffer);
        }

        frame_count++;
        */
    }

    void PostQueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo, VkResult result) {
        
    }

    void PreQueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {

    }

    // 管理Instance(仅一个) device(有多个) queue(一个device对应多个) swapchain(一个device对应多个)
    void PostCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance, VkResult result) {
        if (result == VK_SUCCESS && *pInstance != VK_NULL_HANDLE) {
            instance = *pInstance;
            LOGD("PostCreateInstance success! instance=%p", instance);
        }
    }

    void PreDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
        instance = VK_NULL_HANDLE;
        LOGD("PreDestroyInstance called! instance=%p", instance);
    }


    void PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult result) {
        if (result == VK_SUCCESS && *pDevice != VK_NULL_HANDLE) {
            // 创建DeviceRenderData并存储到map中
            device_render_data_map[*pDevice] = new DeviceRenderData(physicalDevice, *pDevice);
            LOGD("PostCreateDevice success! device=%p", *pDevice);
        }
    }

    void PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
        // 从map中删除对应的 DeviceRenderData
        if (device_render_data_map.count(device) > 0) {
            delete device_render_data_map[device];
            device_render_data_map.erase(device);
            // 好像没触发
            LOGD("PreDestroyDevice called! device=%p", device);
        }
    }

    void PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
        // 获取对应的 DeviceRenderData，存储 queue 和 queue family index 的映射
        /*
        if (device_render_data_map.count(device) > 0) {
            device_render_data_map[device]->AddQueue(*pQueue, queueFamilyIndex);
        }
        */
        DeviceRenderData* device_render_data = GetDeviceRenderData(device);
        if (device_render_data) {
            device_render_data->AddQueue(*pQueue, queueFamilyIndex);
            LOGD("PostGetDeviceQueue called! device=%p, queue=%p, queueFamilyIndex=%u, queueIndex=%u", device, *pQueue, queueFamilyIndex, queueIndex);
        }
    }

    void PostCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain, VkResult result) {
        // 获取对应的 DeviceRenderData，创建 SwapchainRenderData 并存储到 DeviceRenderData 中
        if (result == VK_SUCCESS && pSwapchain != nullptr && *pSwapchain != VK_NULL_HANDLE) {
            DeviceRenderData* device_render_data = GetDeviceRenderData(device);
            if (device_render_data && pCreateInfo != nullptr) {
                // 有必要Remove? 先不remove
                // device_render_data->RemoveSwapchainRenderData(*pSwapchain);

                device_render_data->swapchain_render_data_map[*pSwapchain] = new SwapchainRenderData(device, *pSwapchain, pCreateInfo);
                LOGD("PostCreateSwapchainKHR called! device=%p, swapchain=%p", device, *pSwapchain);
            }
        }
    }

    void PreDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
        // 获取对应的 DeviceRenderData，销毁 SwapchainRenderData 并从 DeviceRenderData 中删除
        DeviceRenderData* device_render_data = GetDeviceRenderData(device);
        if (device_render_data && device_render_data->swapchain_render_data_map.count(swapchain) > 0) {
            delete device_render_data->swapchain_render_data_map[swapchain];
            device_render_data->swapchain_render_data_map.erase(swapchain);

            LOGD("PreDestroySwapchainKHR called! device=%p, swapchain=%p", device, swapchain);
        }
    }

   private:
    ApiHookSettings hook_settings;
    std::mutex output_mutex;
    uint64_t frame_count;

    std::mutex thread_mutex;
    std::unordered_map<std::thread::id, uint64_t> thread_map;

    std::mutex cmd_buffer_state_mutex;
    std::map<std::pair<VkDevice, VkCommandPool>, std::unordered_set<VkCommandBuffer>> cmd_buffer_pools;
    std::unordered_map<VkCommandBuffer, VkCommandBufferLevel> cmd_buffer_level;

    bool first_func_call_on_frame = true;

    std::chrono::system_clock::time_point program_start;

    // Store the VkInstance handle so we don't use null in the call to
    // vkGetInstanceProcAddr(instance_handle, "vkCreateDevice");
    std::unordered_map<VkPhysicalDevice, VkInstance> vk_instance_map;

    // Storage for getCmdBufferLevel() which is called in a place where it needs access to the cmd_buffer but it isn't present in
    // the current structure.
    VkCommandBuffer cmd_buffer;

    // Storage for VkPipelineViewportStateCreateInfo which needs to ignore the scissor and viewport pipeline state if their
    // respective dynamic state is set.
    bool is_dynamic_scissor;
    bool is_dynamic_viewport;

    std::ofstream out_file;




    // --- ImGui 相关 ---
    bool is_imgui_init = false;

    VkInstance instance = VK_NULL_HANDLE;
    std::unordered_map<VkDevice, DeviceRenderData*> device_render_data_map;

    DeviceRenderData* GetDeviceRenderData(VkDevice device) {
        return device_render_data_map[device];
    }

    DeviceRenderData* GetDeviceRenderData(VkQueue queue) {
        for (auto& [device, data] : device_render_data_map) {
            if (data->HasQueue(queue)) {
                return data;
            }
        }
        return nullptr;
    }
};




