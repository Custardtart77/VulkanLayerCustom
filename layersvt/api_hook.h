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
    VkSwapchainKHR swapchain;
    VkDevice device;

    VkExtent2D swapchain_size;
    VkFormat swapchain_format;
    VkSurfaceTransformFlagBitsKHR swapchain_pre_transform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;

    std::vector<VkImageView> swapchain_imageviews;
    std::vector<VkFramebuffer> swapchain_framebuffers;

    VkRenderPass render_pass = VK_NULL_HANDLE;

    VkCommandPool command_pool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> command_buffers;
    uint32_t queue_family = UINT32_MAX;


    std::vector<VkFence> fence;
    std::vector<VkSemaphore> render_finished_semaphore;


    SwapchainRenderData(VkDevice device, VkSwapchainKHR swapchain, const VkSwapchainCreateInfoKHR* pCreateInfo) {
        this->device = device;
        this->swapchain = swapchain;

        swapchain_size = pCreateInfo->imageExtent;
        swapchain_format = pCreateInfo->imageFormat;
        swapchain_pre_transform = pCreateInfo->preTransform;

        CreateImguiRenderPass();
        CreateImguiSwapchainImageViews();
    }

    void CreateImguiRenderPass() {
        // 创建一个简单的 render pass，只有一个 color attachment
        if (render_pass != VK_NULL_HANDLE) {
            return;
        }

        VkAttachmentDescription color_attachment = {};
        color_attachment.format = swapchain_format;
        color_attachment.samples = VK_SAMPLE_COUNT_1_BIT;
        color_attachment.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
        color_attachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        color_attachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        color_attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        color_attachment.initialLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
        color_attachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference color_attachment_ref = {};
        color_attachment_ref.attachment = 0;
        color_attachment_ref.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass = {};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments = &color_attachment_ref;

        VkSubpassDependency subpass_dependency;
        subpass_dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
        subpass_dependency.dstSubpass = 0;
        subpass_dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        subpass_dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        subpass_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        subpass_dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        subpass_dependency.dependencyFlags = 0;

        VkRenderPassCreateInfo render_pass_info = {};
        render_pass_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
        render_pass_info.attachmentCount = 1;
        render_pass_info.pAttachments = &color_attachment;
        render_pass_info.dependencyCount = 1;
        render_pass_info.pDependencies = &subpass_dependency;
        render_pass_info.pSubpasses = &subpass;
        render_pass_info.subpassCount = 1;

        VkResult result = device_dispatch_table(device)->CreateRenderPass(device, &render_pass_info, nullptr, &render_pass);
        if (result != VK_SUCCESS) {
            LOGE("Failed to create render pass! result=%d", result);
        }

        // 这里不能创建CommandBuffer，因为需要在vkQueuePresentKHR中使用CommandBuffer，而vkQueuePresentKHR是在外部调用的，此时还没有创建CommandPool和CommandBuffer，所以只能在vkQueuePresentKHR中创建CommandBuffer
    }

    void CreateImguiSwapchainImageViews() {
        // Implementation for creating swapchain image views
        uint32_t image_count = 0;
        device_dispatch_table(device)->GetSwapchainImagesKHR(device, swapchain, &image_count, nullptr);
        std::vector<VkImage> swapchain_images(image_count);
        device_dispatch_table(device)->GetSwapchainImagesKHR(device, swapchain, &image_count, swapchain_images.data());
        swapchain_imageviews.resize(image_count);

        VkImageViewCreateInfo view_info = {};
        view_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        
        view_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
        view_info.format = swapchain_format;
        view_info.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        view_info.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        view_info.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        view_info.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        view_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        view_info.subresourceRange.baseMipLevel = 0;
        view_info.subresourceRange.levelCount = 1;
        view_info.subresourceRange.baseArrayLayer = 0;
        view_info.subresourceRange.layerCount = 1;
        for (uint32_t i = 0; i < image_count; i++) {
            view_info.image = swapchain_images[i];
            VkResult result = device_dispatch_table(device)->CreateImageView(device, &view_info, nullptr, &swapchain_imageviews[i]);
            if (result != VK_SUCCESS) {
                LOGE("Failed to create image view for swapchain image %u! result=%d", i, result);
            }
        }

        VkFramebufferCreateInfo framebuffer_info = {};
        framebuffer_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebuffer_info.pNext = nullptr;
        framebuffer_info.flags = 0;
        framebuffer_info.renderPass = render_pass;
        framebuffer_info.attachmentCount = 1;
        framebuffer_info.width = swapchain_size.width;
        framebuffer_info.height = swapchain_size.height;
        framebuffer_info.layers = 1;
        swapchain_framebuffers.resize(image_count);
        for (uint32_t i = 0; i < image_count; i++) {
            framebuffer_info.pAttachments = &swapchain_imageviews[i];
            VkResult result = device_dispatch_table(device)->CreateFramebuffer(device, &framebuffer_info, nullptr, &swapchain_framebuffers[i]);
            if (result != VK_SUCCESS) {
                LOGE("Failed to create framebuffer for swapchain image %u! result=%d", i, result);
            }
        }

        // 创建Semaphore和Fence
        render_finished_semaphore.resize(image_count);
        fence.resize(image_count);
        for (uint32_t i = 0; i < image_count; i++) {
            VkSemaphoreCreateInfo semaphore_info = {};
            semaphore_info.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
            VkResult result = device_dispatch_table(device)->CreateSemaphore(device, &semaphore_info, nullptr, &render_finished_semaphore[i]);
            if (result != VK_SUCCESS) {
                LOGE("Failed to create render finished semaphore for swapchain image %u! result=%d", i, result);
            }

            VkFenceCreateInfo fence_info = {};
            fence_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
            fence_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;  // 初始状态为已信号，以便第一次等待时不阻塞
            result = device_dispatch_table(device)->CreateFence(device, &fence_info, nullptr, &fence[i]);
            if (result != VK_SUCCESS) {
                LOGE("Failed to create fence for swapchain image %u! result=%d", i, result);
            }
        }

    }

    void CreateCommandPoolAndCommandBuffers(uint32_t queue_family_index) {
        if (command_pool != VK_NULL_HANDLE) {
            return;
        }

        VkCommandPoolCreateInfo pool_info = {};
        pool_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
        pool_info.queueFamilyIndex = queue_family_index;
        pool_info.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

        VkResult result = device_dispatch_table(device)->CreateCommandPool(device, &pool_info, nullptr, &command_pool);
        if (result != VK_SUCCESS) {
            LOGE("Failed to create command pool! result=%d", result);
        }

        command_buffers.resize(swapchain_imageviews.size());
        VkCommandBufferAllocateInfo alloc_info = {};
        alloc_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        alloc_info.commandPool = command_pool;
        alloc_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandBufferCount = static_cast<uint32_t>(command_buffers.size());
        result = device_dispatch_table(device)->AllocateCommandBuffers(device, &alloc_info, command_buffers.data());
        if (result != VK_SUCCESS) {
            LOGE("Failed to allocate command buffers! result=%d", result);
        }
    }
};

class DeviceRenderData {
   public:
    VkDevice device;
    VkPhysicalDevice physical_device;

    VkDescriptorPool descriptor_pool = VK_NULL_HANDLE;

    std::unordered_map<VkQueue, uint32_t> queue_family_index_map;
    std::unordered_map<VkSwapchainKHR, SwapchainRenderData*> swapchain_render_data_map;

    DeviceRenderData(VkPhysicalDevice physicalDevice, VkDevice device) : physical_device(physicalDevice), device(device) {
        swapchain_render_data_map.clear();
        // 创建descriptor_pool    
        VkDescriptorPoolSize pool_sizes[] =
        {
            { VK_DESCRIPTOR_TYPE_SAMPLER, 10 },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 10 },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, 10 },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, 10 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, 10 },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, 10 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 10 },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 10 },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, 10 },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, 10 },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 10 }
        };

        VkDescriptorPoolCreateInfo pool_info {};
        pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
        pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
        pool_info.maxSets = 10 * (uint32_t)std::size(pool_sizes);
        pool_info.poolSizeCount = (uint32_t)std::size(pool_sizes);
        pool_info.pPoolSizes = pool_sizes;
        VkResult result = device_dispatch_table(device)->CreateDescriptorPool(device, &pool_info, nullptr, &descriptor_pool);
        if (result != VK_SUCCESS) {
            LOGE("Failed to create descriptor pool! result=%d", result);
        }
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


    // 关闭 ImGui
    void ShutdownImGuiVulkan() {
        if (is_imgui_init) {
            ImGui_ImplVulkan_Shutdown();
            ImGui::DestroyContext();
            is_imgui_init = false;
        }
    }

    void RenderImgui(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
        DeviceRenderData* device_render_data = GetDeviceRenderDataByQueue(queue);
        if (!device_render_data) return;
        SwapchainRenderData* swapchain_render_data = device_render_data->swapchain_render_data_map[*pPresentInfo->pSwapchains];
        if (!swapchain_render_data) return;

        VkDevice device = device_render_data->device;

        if (!is_imgui_init) {

            swapchain_render_data->CreateCommandPoolAndCommandBuffers(device_render_data->queue_family_index_map[queue]);

            // InitImGuiVulkan();
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();

            ImGuiIO& io = ImGui::GetIO();
            io.IniFilename = nullptr;
            io.DisplaySize.x = (float)swapchain_render_data->swapchain_size.width;
            io.DisplaySize.y = (float)swapchain_render_data->swapchain_size.height;


            // it works well?
            auto inst_disp = instance_dispatch_table(instance);
            ImGui_ImplVulkan_LoadFunctions(VK_API_VERSION_1_3,
            [](const char* function_name, void* user_data) {
                auto* table = static_cast<VkuInstanceDispatchTable*>(user_data);
                return table->GetInstanceProcAddr(VK_NULL_HANDLE, function_name);
            }, inst_disp);

            // 初始化 Vulkan 渲染后端
            ImGui_ImplVulkan_InitInfo init_info = {};
            init_info.Instance = instance;
            init_info.PhysicalDevice = device_render_data->physical_device;
            init_info.Device = device_render_data->device;
            init_info.QueueFamily = device_render_data->queue_family_index_map[queue];
            init_info.Queue = queue;
            init_info.ApiVersion = VK_API_VERSION_1_3;              

            init_info.PipelineCache = nullptr;
            init_info.DescriptorPool = device_render_data->descriptor_pool;
            init_info.MinImageCount = 2;
            init_info.ImageCount = swapchain_render_data->swapchain_imageviews.size();
            init_info.Allocator = nullptr;
            init_info.PipelineInfoMain.RenderPass = swapchain_render_data->render_pass;
            init_info.PipelineInfoMain.Subpass = 0;
            init_info.PipelineInfoMain.MSAASamples = VK_SAMPLE_COUNT_1_BIT;
            // it works well?
            //init_info.CheckVkResultFn = check_vk_result;

            if (!ImGui_ImplVulkan_Init(&init_info)) {
                return;
            }

            is_imgui_init = true;
        }

        uint32_t image_index = *pPresentInfo->pImageIndices;

        device_dispatch_table(device)->ResetCommandBuffer(swapchain_render_data->command_buffers[image_index], 0);

        VkCommandBufferBeginInfo command_buffer_begin_info = {};
        command_buffer_begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        command_buffer_begin_info.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        VkResult result = device_dispatch_table(device)->BeginCommandBuffer(swapchain_render_data->command_buffers[image_index], &command_buffer_begin_info);
        if (result != VK_SUCCESS) {
            LOGE("Failed to begin command buffer! result=%d", result);
            return;
        }

        VkRenderPassBeginInfo render_pass_begin_info = {};
        render_pass_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_begin_info.renderPass = swapchain_render_data->render_pass;
        render_pass_begin_info.framebuffer = swapchain_render_data->swapchain_framebuffers[image_index];
        render_pass_begin_info.renderArea.offset = {0, 0};
        render_pass_begin_info.renderArea.extent = swapchain_render_data->swapchain_size;
        render_pass_begin_info.clearValueCount = 0;
        render_pass_begin_info.pClearValues = nullptr;

        device_dispatch_table(device)->CmdBeginRenderPass(swapchain_render_data->command_buffers[image_index], &render_pass_begin_info, VK_SUBPASS_CONTENTS_INLINE);

        VkSemaphore wait_semaphores = swapchain_render_data->render_finished_semaphore[image_index];
        // VkFence wait_fences = swapchain_render_data->fence[image_index];

        // ImguiUpdate
        {
            ImGui_ImplVulkan_NewFrame();
            ImGui::NewFrame();

            const ImVec2 window_size { 900.0f, 900.0f };
            ImGui::SetNextWindowSize(window_size);

            const ImVec2 window_pos{ (swapchain_render_data->swapchain_size.width - window_size.x) * 0.5f, (swapchain_render_data->swapchain_size.height - window_size.y) * 0.5f};
            ImGui::SetNextWindowPos(window_pos);
            ImGui::SetNextWindowBgAlpha(0.3f);

            ImGui::Begin("LayerCustomLS");
            ImGui::Text("Hello, Vulkan Layer!");
            ImGui::Text("Frame: %llu", static_cast<unsigned long long>(frame_count));
            
            ImGui::End();
            ImGui::Render();
        }
        ImDrawData* draw_data = ImGui::GetDrawData();
        if (draw_data) {
            // Record dear imgui primitives into command buffer
            ImGui_ImplVulkan_RenderDrawData(draw_data, swapchain_render_data->command_buffers[image_index]);
        }

        frame_count++;
        device_dispatch_table(device)->CmdEndRenderPass(swapchain_render_data->command_buffers[image_index]);
        device_dispatch_table(device)->EndCommandBuffer(swapchain_render_data->command_buffers[image_index]);

        VkSubmitInfo submit_info = {};
        submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.waitSemaphoreCount = 0;
        submit_info.pWaitSemaphores = nullptr;  
        submit_info.pWaitDstStageMask = 0;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers = &swapchain_render_data->command_buffers[image_index];
        submit_info.signalSemaphoreCount = 0;
        submit_info.pSignalSemaphores = &wait_semaphores;;
        result = device_dispatch_table(device)->QueueSubmit(queue, 1, &submit_info, swapchain_render_data->fence[image_index]);
        if (result != VK_SUCCESS) {
            LOGE("Failed to submit command buffer! result=%d", result);
            return;
        }

        // fence和semaphore待设置
        // 

    }

    void PostQueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo, VkResult result) {
        
    }

    void PreQueuePresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
        RenderImgui(queue, pPresentInfo);
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
        DeviceRenderData* device_render_data = GetDeviceRenderDataByDevice(device);
        if (device_render_data) {
            device_render_data->AddQueue(*pQueue, queueFamilyIndex);
            LOGD("PostGetDeviceQueue called! device=%p, queue=%p, queueFamilyIndex=%u, queueIndex=%u", device, *pQueue, queueFamilyIndex, queueIndex);
        }
    }

    void PostCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain, VkResult result) {
        // 获取对应的 DeviceRenderData，创建 SwapchainRenderData 并存储到 DeviceRenderData 中
        if (result == VK_SUCCESS && pSwapchain != nullptr && *pSwapchain != VK_NULL_HANDLE) {
            DeviceRenderData* device_render_data = GetDeviceRenderDataByDevice(device);
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
        DeviceRenderData* device_render_data = GetDeviceRenderDataByDevice(device);
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

    DeviceRenderData* GetDeviceRenderDataByDevice(VkDevice device) {
        return device_render_data_map[device];
    }

    DeviceRenderData* GetDeviceRenderDataByQueue(VkQueue queue) {
        for (auto& [device, data] : device_render_data_map) {
            if (data->HasQueue(queue)) {
                return data;
            }
        }
        return nullptr;
    }
};




