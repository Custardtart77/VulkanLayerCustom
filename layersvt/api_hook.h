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

    void setCmdBuffer(VkCommandBuffer cmd_buffer) { this->cmd_buffer = cmd_buffer; }

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
};
