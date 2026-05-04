
/* Copyright (c) 2015-2026 Valve Corporation
 * Copyright (c) 2015-2026 LunarG, Inc.
 * Copyright (c) 2015-2017, 2019, 2021 Google Inc.
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
 */

/*
 * This file is generated from the Khronos Vulkan XML API Registry.
 */

#include "api_hook_handwritten_functions.h"

// Autogen instance functions
// if vk api needs to be safe, "std::lock_guard<std::mutex> lg(ApiHookInstance::current().outputMutex());" can be added before each vk* function
VKAPI_ATTR void VKAPI_CALL vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex

    auto dispatch_key = get_dispatch_key(instance);
    instance_dispatch_table(instance)->DestroyInstance(instance, pAllocator);
    destroy_instance_dispatch_table(dispatch_key);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    if (pPhysicalDeviceCount != nullptr && pPhysicalDevices != nullptr) {
        for (uint32_t i = 0; i < *pPhysicalDeviceCount; i++) {
            ApiHookInstance::current().set_vk_instance(pPhysicalDevices[i], instance);
        }
    }
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex

    instance_dispatch_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);
    return result;
}
#endif  // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);
    return result;
}
#endif  // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);
    return result;
}
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoCapabilitiesKHR(physicalDevice, pVideoProfile, pCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoFormatPropertiesKHR(physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(physicalDevice, pPerformanceQueryCreateInfo, pNumPasses);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceFragmentShadingRatesKHR(physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(physicalDevice, pQualityLevelInfo, pQualityLevelProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesKHR(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsKHR(physicalDevice, pTimeDomainCount, pTimeDomains);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex

    instance_dispatch_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) {
    // pad: mutex

    instance_dispatch_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}
#if defined(VK_USE_PLATFORM_GGP)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateStreamDescriptorSurfaceGGP(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_GGP
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_VI_NN)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_VI_NN
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);
    return result;
}
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);
    return result;
}
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);
    return result;
}
#if defined(VK_USE_PLATFORM_IOS_MVK)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_MACOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex

    instance_dispatch_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) {
    // pad: mutex

    instance_dispatch_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);
}
VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetPhysicalDeviceDescriptorSizeEXT(VkPhysicalDevice physicalDevice, VkDescriptorType descriptorType) {
    // pad: mutex

    VkDeviceSize result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDescriptorSizeEXT(physicalDevice, descriptorType);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCalibrateableTimeDomainsEXT(physicalDevice, pTimeDomainCount, pTimeDomains);
    return result;
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateImagePipeSurfaceFUCHSIA(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateMetalSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_METAL_EXT
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    // pad: mutex


    static const VkPhysicalDeviceToolPropertiesEXT api_dump_layer_tool_props = {
        VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
        nullptr,
        "API Dump Layer",
        "2",
        VK_TOOL_PURPOSE_PROFILING_BIT_EXT | VK_TOOL_PURPOSE_TRACING_BIT_EXT,
        "The VK_LAYER_LUNARG_api_dump utility layer prints API calls, parameters, and values to the identified output stream.",
        "VK_LAYER_LUNARG_api_dump"};

    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr) {
        *pToolProperties = api_dump_layer_tool_props;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);
    if (original_pToolProperties != nullptr) {
        pToolProperties = original_pToolProperties;
    }

    (*pToolCount)++;
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(physicalDevice, pCombinationCount, pCombinations);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModes2EXT(physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateHeadlessSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->AcquireDrmDisplayEXT(physicalDevice, drmFd, display);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetDrmDisplayEXT(physicalDevice, drmFd, connectorId, display);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->AcquireWinrtDisplayNV(physicalDevice, display);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetWinrtDisplayNV(physicalDevice, deviceRelativeId, pDisplay);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateDirectFBSurfaceEXT(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceDirectFBPresentationSupportEXT(physicalDevice, queueFamilyIndex, dfb);
    return result;
}
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateScreenSurfaceQNX(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceScreenPresentationSupportQNX(physicalDevice, queueFamilyIndex, window);
    return result;
}
#endif  // VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM* pExternalTensorInfo, VkExternalTensorPropertiesARM* pExternalTensorProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceExternalTensorPropertiesARM(physicalDevice, pExternalTensorInfo, pExternalTensorProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceOpticalFlowImageFormatsNV(physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeVectorPropertiesNV* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeVectorPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphPropertyCount, pQueueFamilyDataGraphProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* pQueueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM* pQueueFamilyDataGraphProcessingEngineProperties) {
    // pad: mutex

    instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(physicalDevice, pQueueFamilyDataGraphProcessingEngineInfo, pQueueFamilyDataGraphProcessingEngineProperties);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, const VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties, VkBaseOutStructure* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphProperties, pProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_OHOS)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateSurfaceOHOS(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
#endif  // VK_USE_PLATFORM_OHOS
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV* pProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(physicalDevice, pPropertyCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterARM* pCounters, VkPerformanceCounterDescriptionARM* pCounterDescriptions) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEnumeratePhysicalDeviceShaderInstrumentationMetricsARM(VkPhysicalDevice physicalDevice, uint32_t* pDescriptionCount, VkShaderInstrumentationMetricDescriptionARM* pDescriptions) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->EnumeratePhysicalDeviceShaderInstrumentationMetricsARM(physicalDevice, pDescriptionCount, pDescriptions);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, const VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties, const VkDataGraphOpticalFlowImageFormatInfoARM* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkDataGraphOpticalFlowImageFormatPropertiesARM* pImageFormatProperties) {
    // pad: mutex

    VkResult result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(physicalDevice, queueFamilyIndex, pQueueFamilyDataGraphProperties, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_UBM_SEC)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateUbmSurfaceSEC(VkInstance instance, const VkUbmSurfaceCreateInfoSEC* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) {
    // pad: mutex

    VkResult result = instance_dispatch_table(instance)->CreateUbmSurfaceSEC(instance, pCreateInfo, pAllocator, pSurface);
    return result;
}
VKAPI_ATTR VkBool32 VKAPI_CALL vkGetPhysicalDeviceUbmPresentationSupportSEC(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct ubm_device* device) {
    // pad: mutex

    VkBool32 result = instance_dispatch_table(physicalDevice)->GetPhysicalDeviceUbmPresentationSupportSEC(physicalDevice, queueFamilyIndex, device);
    return result;
}
#endif  // VK_USE_PLATFORM_UBM_SEC

// Autogen device functions

VKAPI_ATTR void VKAPI_CALL vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDevice(device, pAllocator);
    destroy_device_dispatch_table(get_dispatch_key(device));
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueWaitIdle(VkQueue queue) {
    VkResult result = device_dispatch_table(queue)->QueueWaitIdle(queue);
    // pad: mutex
    
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDeviceWaitIdle(VkDevice device) {
    VkResult result = device_dispatch_table(device)->DeviceWaitIdle(device);
    // pad: mutex
    
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->FreeMemory(device, memory, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->MapMemory(device, memory, offset, size, flags, ppData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUnmapMemory(VkDevice device, VkDeviceMemory memory) {
    // pad: mutex


    device_dispatch_table(device)->UnmapMemory(device, memory);
}
VKAPI_ATTR VkResult VKAPI_CALL vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindImageMemory(device, image, memory, memoryOffset);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyFence(device, fence, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ResetFences(device, fenceCount, pFences);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceStatus(VkDevice device, VkFence fence) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetFenceStatus(device, fence);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);
    // pad: mutex
    
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroySemaphore(device, semaphore, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyQueryPool(device, queryPool, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) {
    VkResult result = device_dispatch_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
    // pad: mutex
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyBuffer(device, buffer, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyImage(device, image, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyImageView(device, imageView, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyCommandPool(device, commandPool, pAllocator);
    ApiHookInstance::current().eraseCmdBufferPool(device, commandPool);
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ResetCommandPool(device, commandPool, flags);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
    if (result == VK_SUCCESS)
        ApiHookInstance::current().addCmdBuffers(
            device,
            pAllocateInfo->commandPool,
            std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + pAllocateInfo->commandBufferCount),
            pAllocateInfo->level);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
    // pad: mutex


    device_dispatch_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
    ApiHookInstance::current().eraseCmdBuffers(device, commandPool, std::vector<VkCommandBuffer>(pCommandBuffers, pCommandBuffers + commandBufferCount));
}
VKAPI_ATTR VkResult VKAPI_CALL vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkEndCommandBuffer(VkCommandBuffer commandBuffer) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->EndCommandBuffer(commandBuffer);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}
VKAPI_ATTR void VKAPI_CALL vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyEvent(device, event, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetEventStatus(VkDevice device, VkEvent event) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetEventStatus(device, event);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetEvent(VkDevice device, VkEvent event) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetEvent(device, event);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetEvent(VkDevice device, VkEvent event) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ResetEvent(device, event);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyBufferView(device, bufferView, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPipeline(device, pipeline, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroySampler(device, sampler, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ResetDescriptorPool(device, descriptorPool, flags);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) {
    // pad: mutex


    device_dispatch_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyRenderPass(device, renderPass, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) {
    // pad: mutex


    device_dispatch_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}
VKAPI_ATTR void VKAPI_CALL vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRenderPass(commandBuffer);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    // pad: mutex


    device_dispatch_table(device)->TrimCommandPool(device, commandPool, flags);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
    // pad: mutex


    device_dispatch_table(device)->UpdateDescriptorSetWithTemplate(device, descriptorSet, descriptorUpdateTemplate, pData);
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    // pad: mutex


    device_dispatch_table(device)->ResetQueryPool(device, queryPool, firstQuery, queryCount);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValue(device, semaphore, pValue);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitSemaphores(device, pWaitInfo, timeout);
    // pad: mutex
    
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SignalSemaphore(device, pSignalInfo);
    return result;
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    // pad: mutex


    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddress(device, pInfo);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddress(device, pInfo);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress(device, pInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCount(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateRenderPass2(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdNextSubpass2(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRenderPass2(commandBuffer, pSubpassEndInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlot(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPrivateDataSlot(device, privateDataSlot, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    // pad: mutex


    device_dispatch_table(device)->GetPrivateData(device, objectType, objectHandle, privateDataSlot, pData);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2(commandBuffer, pDependencyInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2(commandBuffer, stage, queryPool, query);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueSubmit2(queue, submitCount, pSubmits, fence);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImage2(commandBuffer, pCopyImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceBufferMemoryRequirements(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageMemoryRequirements(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetEvent2(commandBuffer, event, pDependencyInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResetEvent2(commandBuffer, event, stageMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWaitEvents2(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBlitImage2(commandBuffer, pBlitImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResolveImage2(commandBuffer, pResolveImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginRendering(commandBuffer, pRenderingInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRendering(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCullMode(commandBuffer, cullMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetFrontFace(commandBuffer, frontFace);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopology(commandBuffer, primitiveTopology);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportWithCount(commandBuffer, viewportCount, pViewports);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetScissorWithCount(commandBuffer, scissorCount, pScissors);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnable(commandBuffer, depthTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnable(commandBuffer, depthWriteEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOp(commandBuffer, depthCompareOp);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnable(commandBuffer, depthBoundsTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnable(commandBuffer, stencilTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilOp(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnable(commandBuffer, rasterizerDiscardEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnable(commandBuffer, depthBiasEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnable(commandBuffer, primitiveRestartEnable);
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->MapMemory2(device, pMemoryMapInfo, ppData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->UnmapMemory2(device, pMemoryUnmapInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageSubresourceLayout(device, pInfo, pLayout);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSubresourceLayout2(device, image, pSubresource, pLayout);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMemoryToImage(device, pCopyMemoryToImageInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyImageToMemory(device, pCopyImageToMemoryInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyImageToImage(device, pCopyImageToImageInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->TransitionImageLayout(device, transitionCount, pTransitions);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets2(commandBuffer, pBindDescriptorSetsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushConstants2(commandBuffer, pPushConstantsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet2(commandBuffer, pPushDescriptorSetInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate2(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineStipple(commandBuffer, lineStippleFactor, lineStipplePattern);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer2(commandBuffer, buffer, offset, size, indexType);
}
VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
    // pad: mutex


    device_dispatch_table(device)->GetRenderingAreaGranularity(device, pRenderingAreaInfo, pGranularity);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRenderingAttachmentLocations(commandBuffer, pLocationInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRenderingInputAttachmentIndices(commandBuffer, pInputAttachmentIndexInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    VkResult result = device_dispatch_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);
    // pad: mutex
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) {
    VkResult result = device_dispatch_table(queue)->QueuePresentKHR(queue, pPresentInfo);
    // pad: mutex
    // LOGD("vkQueuePresentKHR");
    
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateVideoSessionKHR(device, pCreateInfo, pAllocator, pVideoSession);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyVideoSessionKHR(device, videoSession, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR(device, videoSession, pMemoryRequirementsCount, pMemoryRequirements);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindVideoSessionMemoryKHR(device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateVideoSessionParametersKHR(device, pCreateInfo, pAllocator, pVideoSessionParameters);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->UpdateVideoSessionParametersKHR(device, videoSessionParameters, pUpdateInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyVideoSessionParametersKHR(device, videoSessionParameters, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginVideoCodingKHR(commandBuffer, pBeginInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndVideoCodingKHR(commandBuffer, pEndCodingInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdControlVideoCodingKHR(commandBuffer, pCodingControlInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDecodeVideoKHR(commandBuffer, pDecodeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderingKHR(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRenderingKHR(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
VKAPI_ATTR void VKAPI_CALL vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) {
    // pad: mutex


    device_dispatch_table(device)->TrimCommandPoolKHR(device, commandPool, flags);
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplateKHR(commandBuffer, descriptorUpdateTemplate, layout, set, pData);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) {
    // pad: mutex


    device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR(device, descriptorSet, descriptorUpdateTemplate, pData);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSwapchainStatusKHR(device, swapchain);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AcquireProfilingLockKHR(device, pInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkReleaseProfilingLockKHR(VkDevice device) {
    // pad: mutex


    device_dispatch_table(device)->ReleaseProfilingLockKHR(device);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSemaphoreCounterValueKHR(device, semaphore, pValue);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) {
    VkResult result = device_dispatch_table(device)->WaitSemaphoresKHR(device, pWaitInfo, timeout);
    // pad: mutex
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SignalSemaphoreKHR(device, pSignalInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateKHR(commandBuffer, pFragmentSize, combinerOps);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRenderingAttachmentLocationsKHR(commandBuffer, pLocationInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRenderingInputAttachmentIndicesKHR(commandBuffer, pInputAttachmentIndexInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WaitForPresentKHR(device, swapchain, presentId, timeout);
    return result;
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    // pad: mutex


    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressKHR(device, pInfo);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR(device, pInfo);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(device, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDeferredOperationKHR(device, pAllocator, pDeferredOperation);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDeferredOperationKHR(device, operation, pAllocator);
}
VKAPI_ATTR uint32_t VKAPI_CALL vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) {
    // pad: mutex


    uint32_t result = device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR(device, operation);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeferredOperationResultKHR(device, operation);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->DeferredOperationJoinKHR(device, operation);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR(device, pPipelineInfo, pExecutableCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR(device, pExecutableInfo, pStatisticCount, pStatistics);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR(device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->MapMemory2KHR(device, pMemoryMapInfo, ppData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->UnmapMemory2KHR(device, pMemoryUnmapInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR(device, pVideoSessionParametersInfo, pFeedbackInfo, pDataSize, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEncodeVideoKHR(commandBuffer, pEncodeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetEvent2KHR(commandBuffer, event, pDependencyInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResetEvent2KHR(commandBuffer, event, stageMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWaitEvents2KHR(commandBuffer, eventCount, pEvents, pDependencyInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPipelineBarrier2KHR(commandBuffer, pDependencyInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteTimestamp2KHR(commandBuffer, stage, queryPool, query);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer3KHR(VkCommandBuffer commandBuffer, const VkBindIndexBuffer3InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer3KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers3KHR(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBindVertexBuffer3InfoKHR* pBindingInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers3KHR(commandBuffer, firstBinding, bindingCount, pBindingInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirect2KHR(VkCommandBuffer commandBuffer, const VkDrawIndirect2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirect2KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirect2KHR(VkCommandBuffer commandBuffer, const VkDrawIndirect2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirect2KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchIndirect2KHR(VkCommandBuffer commandBuffer, const VkDispatchIndirect2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchIndirect2KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyDeviceMemoryInfoKHR* pCopyMemoryInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryKHR(commandBuffer, pCopyMemoryInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageKHR(VkCommandBuffer commandBuffer, const VkCopyDeviceMemoryImageInfoKHR* pCopyMemoryInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageKHR(commandBuffer, pCopyMemoryInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyDeviceMemoryImageInfoKHR* pCopyMemoryInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImageToMemoryKHR(commandBuffer, pCopyMemoryInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdUpdateMemoryKHR(VkCommandBuffer commandBuffer, const VkDeviceAddressRangeKHR* pDstRange, VkAddressCommandFlagsKHR dstFlags, VkDeviceSize dataSize, const void* pData) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdUpdateMemoryKHR(commandBuffer, pDstRange, dstFlags, dataSize, pData);
}
VKAPI_ATTR void VKAPI_CALL vkCmdFillMemoryKHR(VkCommandBuffer commandBuffer, const VkDeviceAddressRangeKHR* pDstRange, VkAddressCommandFlagsKHR dstFlags, uint32_t data) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdFillMemoryKHR(commandBuffer, pDstRange, dstFlags, data);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyQueryPoolResultsToMemoryKHR(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, const VkStridedDeviceAddressRangeKHR* pDstRange, VkAddressCommandFlagsKHR dstFlags, VkQueryResultFlags queryResultFlags) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyQueryPoolResultsToMemoryKHR(commandBuffer, queryPool, firstQuery, queryCount, pDstRange, dstFlags, queryResultFlags);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCount2KHR(VkCommandBuffer commandBuffer, const VkDrawIndirectCount2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectCount2KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCount2KHR(VkCommandBuffer commandBuffer, const VkDrawIndirectCount2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCount2KHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRendering2EXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfo2EXT* pConditionalRenderingBegin) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginConditionalRendering2EXT(commandBuffer, pConditionalRenderingBegin);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBindTransformFeedbackBuffer2InfoEXT* pBindingInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindTransformFeedbackBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBindingInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedback2EXT(VkCommandBuffer commandBuffer, uint32_t firstCounterRange, uint32_t counterRangeCount, const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginTransformFeedback2EXT(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedback2EXT(VkCommandBuffer commandBuffer, uint32_t firstCounterRange, uint32_t counterRangeCount, const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndTransformFeedback2EXT(commandBuffer, firstCounterRange, counterRangeCount, pCounterInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCount2EXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, const VkBindTransformFeedbackBuffer2InfoEXT* pCounterInfo, uint32_t counterOffset, uint32_t vertexStride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectByteCount2EXT(commandBuffer, instanceCount, firstInstance, pCounterInfo, counterOffset, vertexStride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirect2EXT(VkCommandBuffer commandBuffer, const VkDrawIndirect2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirect2EXT(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCount2EXT(VkCommandBuffer commandBuffer, const VkDrawIndirectCount2InfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCount2EXT(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteMarkerToMemoryAMD(VkCommandBuffer commandBuffer, const VkMemoryMarkerInfoAMD* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteMarkerToMemoryAMD(commandBuffer, pInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructure2KHR(VkDevice device, const VkAccelerationStructureCreateInfo2KHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateAccelerationStructure2KHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBuffer2KHR(commandBuffer, pCopyBufferInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImage2KHR(commandBuffer, pCopyImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyBufferToImage2KHR(commandBuffer, pCopyBufferToImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyImageToBuffer2KHR(commandBuffer, pCopyImageToBufferInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBlitImage2KHR(commandBuffer, pBlitImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdResolveImage2KHR(commandBuffer, pResolveImageInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirect2KHR(commandBuffer, indirectDeviceAddress);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindIndexBuffer2KHR(commandBuffer, buffer, offset, size, indexType);
}
VKAPI_ATTR void VKAPI_CALL vkGetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) {
    // pad: mutex


    device_dispatch_table(device)->GetRenderingAreaGranularityKHR(device, pRenderingAreaInfo, pGranularity);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR(device, pInfo, pLayout);
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSubresourceLayout2KHR(device, image, pSubresource, pLayout);
}
VKAPI_ATTR VkResult VKAPI_CALL vkWaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WaitForPresent2KHR(device, swapchain, pPresentWait2Info);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreatePipelineBinariesKHR(device, pCreateInfo, pAllocator, pBinaries);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPipelineBinaryKHR(device, pipelineBinary, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineKeyKHR(device, pPipelineCreateInfo, pPipelineKey);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelineBinaryDataKHR(device, pInfo, pPipelineBinaryKey, pPipelineBinaryDataSize, pPipelineBinaryData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ReleaseCapturedPipelineDataKHR(device, pInfo, pAllocator);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ReleaseSwapchainImagesKHR(device, pReleaseInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineStippleKHR(commandBuffer, lineStippleFactor, lineStipplePattern);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsKHR(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushConstants2KHR(commandBuffer, pPushConstantsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSet2KHR(commandBuffer, pPushDescriptorSetInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDescriptorSetWithTemplate2KHR(commandBuffer, pPushDescriptorSetWithTemplateInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsets2EXT(commandBuffer, pSetDescriptorBufferOffsetsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplers2EXT(commandBuffer, pBindDescriptorBufferEmbeddedSamplersInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryIndirectKHR(commandBuffer, pCopyMemoryIndirectInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageIndirectKHR(commandBuffer, pCopyMemoryToImageIndirectInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultReportsKHR(VkDevice device, uint64_t timeout, uint32_t* pFaultCounts, VkDeviceFaultInfoKHR* pFaultInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceFaultReportsKHR(device, timeout, pFaultCounts, pFaultInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultDebugInfoKHR(VkDevice device, VkDeviceFaultDebugInfoKHR* pDebugInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceFaultDebugInfoKHR(device, pDebugInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2KHR(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRendering2KHR(commandBuffer, pRenderingEndInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindTransformFeedbackBuffersEXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndTransformFeedbackEXT(commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginQueryIndexedEXT(commandBuffer, queryPool, query, flags, index);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndQueryIndexedEXT(commandBuffer, queryPool, query, index);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectByteCountEXT(commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateCuModuleNVX(device, pCreateInfo, pAllocator, pModule);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateCuFunctionNVX(device, pCreateInfo, pAllocator, pFunction);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyCuModuleNVX(device, module, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyCuFunctionNVX(device, function, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCuLaunchKernelNVX(commandBuffer, pLaunchInfo);
}
VKAPI_ATTR uint32_t VKAPI_CALL vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
    // pad: mutex


    uint32_t result = device_dispatch_table(device)->GetImageViewHandleNVX(device, pInfo);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetImageViewHandle64NVX(device, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetImageViewAddressNVX(device, imageView, pProperties);
    return result;
}
VKAPI_ATTR uint64_t VKAPI_CALL vkGetDeviceCombinedImageSamplerIndexNVX(VkDevice device, uint64_t imageViewIndex, uint64_t samplerIndex) {
    // pad: mutex


    uint64_t result = device_dispatch_table(device)->GetDeviceCombinedImageSamplerIndexNVX(device, imageViewIndex, samplerIndex);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR void VKAPI_CALL vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}
VKAPI_ATTR VkResult VKAPI_CALL vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleEnableEXT(commandBuffer, discardRectangleEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDiscardRectangleModeEXT(commandBuffer, discardRectangleMode);
}
VKAPI_ATTR void VKAPI_CALL vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) {
    // pad: mutex


    device_dispatch_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    // pad: mutex


    device_dispatch_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);
}
VKAPI_ATTR void VKAPI_CALL vkQueueEndDebugUtilsLabelEXT(VkQueue queue) {
    // pad: mutex


    device_dispatch_table(queue)->QueueEndDebugUtilsLabelEXT(queue);
}
VKAPI_ATTR void VKAPI_CALL vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) {
    // pad: mutex


    device_dispatch_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);
}
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);
    return result;
}
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExecutionGraphPipelinesAMDX(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineScratchSizeAMDX(VkDevice device, VkPipeline executionGraph, VkExecutionGraphPipelineScratchSizeAMDX* pSizeInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX(device, executionGraph, pSizeInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice device, VkPipeline executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX* pNodeInfo, uint32_t* pNodeIndex) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX(device, executionGraph, pNodeInfo, pNodeIndex);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkPipeline executionGraph, VkDeviceAddress scratch, VkDeviceSize scratchSize) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdInitializeGraphScratchMemoryAMDX(commandBuffer, executionGraph, scratch, scratchSize);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchGraphAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectAMDX(commandBuffer, scratch, scratchSize, pCountInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, VkDeviceAddress countInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchGraphIndirectCountAMDX(commandBuffer, scratch, scratchSize, countInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS
VKAPI_ATTR VkResult VKAPI_CALL vkWriteSamplerDescriptorsEXT(VkDevice device, uint32_t samplerCount, const VkSamplerCreateInfo* pSamplers, const VkHostAddressRangeEXT* pDescriptors) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WriteSamplerDescriptorsEXT(device, samplerCount, pSamplers, pDescriptors);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWriteResourceDescriptorsEXT(VkDevice device, uint32_t resourceCount, const VkResourceDescriptorInfoEXT* pResources, const VkHostAddressRangeEXT* pDescriptors) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WriteResourceDescriptorsEXT(device, resourceCount, pResources, pDescriptors);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindSamplerHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindSamplerHeapEXT(commandBuffer, pBindInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindResourceHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindResourceHeapEXT(commandBuffer, pBindInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPushDataEXT(VkCommandBuffer commandBuffer, const VkPushDataInfoEXT* pPushDataInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPushDataEXT(commandBuffer, pPushDataInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDataEXT(VkDevice device, uint32_t imageCount, const VkImage* pImages, VkHostAddressRangeEXT* pDatas) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetImageOpaqueCaptureDataEXT(device, imageCount, pImages, pDatas);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkRegisterCustomBorderColorEXT(VkDevice device, const VkSamplerCustomBorderColorCreateInfoEXT* pBorderColor, VkBool32 requestIndex, uint32_t* pIndex) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->RegisterCustomBorderColorEXT(device, pBorderColor, requestIndex, pIndex);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUnregisterCustomBorderColorEXT(VkDevice device, uint32_t index) {
    // pad: mutex


    device_dispatch_table(device)->UnregisterCustomBorderColorEXT(device, index);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorOpaqueCaptureDataARM(VkDevice device, uint32_t tensorCount, const VkTensorARM* pTensors, VkHostAddressRangeEXT* pDatas) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetTensorOpaqueCaptureDataARM(device, tensorCount, pTensors, pDatas);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT(device, image, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindShadingRateImageNV(commandBuffer, imageView, imageLayout);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportShadingRatePaletteNV(commandBuffer, firstViewport, viewportCount, pShadingRatePalettes);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoarseSampleOrderNV(commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureNV(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyAccelerationStructureNV(device, accelerationStructure, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindAccelerationStructureMemoryNV(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructureNV(commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureNV(commandBuffer, dst, src, mode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdTraceRaysNV(commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesNV(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetAccelerationStructureHandleNV(device, accelerationStructure, dataSize, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesNV(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CompileDeferredNV(device, pipeline, shader);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteBufferMarker2AMD(commandBuffer, stage, dstBuffer, dstOffset, marker);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetCalibratedTimestampsEXT(device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksNV(commandBuffer, taskCount, firstTask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectNV(commandBuffer, buffer, offset, drawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountNV(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorEnableNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetExclusiveScissorNV(commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCheckpointNV(commandBuffer, pCheckpointMarker);
}
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) {
    // pad: mutex


    device_dispatch_table(queue)->GetQueueCheckpointDataNV(queue, pCheckpointDataCount, pCheckpointData);
}
VKAPI_ATTR void VKAPI_CALL vkGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) {
    // pad: mutex


    device_dispatch_table(queue)->GetQueueCheckpointData2NV(queue, pCheckpointDataCount, pCheckpointData);
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetSwapchainPresentTimingQueueSizeEXT(VkDevice device, VkSwapchainKHR swapchain, uint32_t size) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetSwapchainPresentTimingQueueSizeEXT(device, swapchain, size);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimingPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimingPropertiesEXT* pSwapchainTimingProperties, uint64_t* pSwapchainTimingPropertiesCounter) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSwapchainTimingPropertiesEXT(device, swapchain, pSwapchainTimingProperties, pSwapchainTimingPropertiesCounter);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSwapchainTimeDomainPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimeDomainPropertiesEXT* pSwapchainTimeDomainProperties, uint64_t* pTimeDomainsCounter) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSwapchainTimeDomainPropertiesEXT(device, swapchain, pSwapchainTimeDomainProperties, pTimeDomainsCounter);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPastPresentationTimingEXT(VkDevice device, const VkPastPresentationTimingInfoEXT* pPastPresentationTimingInfo, VkPastPresentationTimingPropertiesEXT* pPastPresentationTimingProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPastPresentationTimingEXT(device, pPastPresentationTimingInfo, pPastPresentationTimingProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->InitializePerformanceApiINTEL(device, pInitializeInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkUninitializePerformanceApiINTEL(VkDevice device) {
    // pad: mutex


    device_dispatch_table(device)->UninitializePerformanceApiINTEL(device);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceMarkerINTEL(commandBuffer, pMarkerInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceStreamMarkerINTEL(commandBuffer, pMarkerInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(commandBuffer)->CmdSetPerformanceOverrideINTEL(commandBuffer, pOverrideInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL(device, pAcquireInfo, pConfiguration);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL(device, configuration);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueSetPerformanceConfigurationINTEL(queue, configuration);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPerformanceParameterINTEL(device, parameter, pValue);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) {
    // pad: mutex


    device_dispatch_table(device)->SetLocalDimmingAMD(device, swapChain, localDimmingEnable);
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) {
    // pad: mutex


    VkDeviceAddress result = device_dispatch_table(device)->GetBufferDeviceAddressEXT(device, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT(device, swapchain);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT(device, swapchain);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT(device, pSurfaceInfo, pModes);
    return result;
}
#endif  // VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineStippleEXT(commandBuffer, lineStippleFactor, lineStipplePattern);
}
VKAPI_ATTR void VKAPI_CALL vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) {
    // pad: mutex


    device_dispatch_table(device)->ResetQueryPoolEXT(device, queryPool, firstQuery, queryCount);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCullModeEXT(commandBuffer, cullMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetFrontFaceEXT(commandBuffer, frontFace);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPrimitiveTopologyEXT(commandBuffer, primitiveTopology);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportWithCountEXT(commandBuffer, viewportCount, pViewports);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetScissorWithCountEXT(commandBuffer, scissorCount, pScissors);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindVertexBuffers2EXT(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthTestEnableEXT(commandBuffer, depthTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthWriteEnableEXT(commandBuffer, depthWriteEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthCompareOpEXT(commandBuffer, depthCompareOp);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBoundsTestEnableEXT(commandBuffer, depthBoundsTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilTestEnableEXT(commandBuffer, stencilTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetStencilOpEXT(commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMemoryToImageEXT(device, pCopyMemoryToImageInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyImageToMemoryEXT(device, pCopyImageToMemoryInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyImageToImageEXT(device, pCopyImageToImageInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->TransitionImageLayoutEXT(device, transitionCount, pTransitions);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) {
    // pad: mutex


    device_dispatch_table(device)->GetImageSubresourceLayout2EXT(device, image, pSubresource, pLayout);
}
VKAPI_ATTR VkResult VKAPI_CALL vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ReleaseSwapchainImagesEXT(device, pReleaseInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPreprocessGeneratedCommandsNV(commandBuffer, pGeneratedCommandsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdExecuteGeneratedCommandsNV(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindPipelineShaderGroupNV(commandBuffer, pipelineBindPoint, pipeline, groupIndex);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateIndirectCommandsLayoutNV(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV(device, indirectCommandsLayout, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBias2EXT(commandBuffer, pDepthBiasInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreatePrivateDataSlotEXT(device, pCreateInfo, pAllocator, pPrivateDataSlot);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyPrivateDataSlotEXT(device, privateDataSlot, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, data);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) {
    // pad: mutex


    device_dispatch_table(device)->GetPrivateDataEXT(device, objectType, objectHandle, privateDataSlot, pData);
}
VKAPI_ATTR VkResult VKAPI_CALL vkQueueSetPerfHintQCOM(VkQueue queue, const VkPerfHintInfoQCOM* pPerfHintInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(queue)->QueueSetPerfHintQCOM(queue, pPerfHintInfo);
    return result;
}
#if defined(VK_ENABLE_BETA_EXTENSIONS)
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateCudaModuleNV(device, pCreateInfo, pAllocator, pModule);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetCudaModuleCacheNV(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetCudaModuleCacheNV(device, module, pCacheSize, pCacheData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateCudaFunctionNV(device, pCreateInfo, pAllocator, pFunction);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyCudaModuleNV(device, module, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyCudaFunctionNV(device, function, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCudaLaunchKernelNV(commandBuffer, pLaunchInfo);
}
#endif  // VK_ENABLE_BETA_EXTENSIONS
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchTileQCOM(commandBuffer, pDispatchTileInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginPerTileExecutionQCOM(commandBuffer, pPerTileBeginInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndPerTileExecutionQCOM(commandBuffer, pPerTileEndInfo);
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
VKAPI_ATTR void VKAPI_CALL vkExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) {
    // pad: mutex


    device_dispatch_table(device)->ExportMetalObjectsEXT(device, pMetalObjectsInfo);
}
#endif  // VK_USE_PLATFORM_METAL_EXT
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT(device, layout, pLayoutSizeInBytes);
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT(device, layout, binding, pOffset);
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorEXT(device, pDescriptorInfo, dataSize, pDescriptor);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorBuffersEXT(commandBuffer, bufferCount, pBindingInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDescriptorBufferOffsetsEXT(commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindDescriptorBufferEmbeddedSamplersEXT(commandBuffer, pipelineBindPoint, layout, set);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(device, pInfo, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetFragmentShadingRateEnumNV(commandBuffer, shadingRate, combinerOps);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceFaultInfoEXT(device, pFaultCounts, pFaultInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetVertexInputEXT(commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions);
}
#if defined(VK_USE_PLATFORM_FUCHSIA)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA(device, handleType, zirconHandle, pMemoryZirconHandleProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA(device, pImportSemaphoreZirconHandleInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA(device, pGetZirconHandleInfo, pZirconHandle);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateBufferCollectionFUCHSIA(device, pCreateInfo, pAllocator, pCollection);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA(device, collection, pImageConstraintsInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA(device, collection, pBufferConstraintsInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA(device, collection, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA(device, collection, pProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_FUCHSIA
VKAPI_ATTR VkResult VKAPI_CALL vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(device, renderpass, pMaxWorkgroupSize);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSubpassShadingHUAWEI(commandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindInvocationMaskHUAWEI(commandBuffer, imageView, imageLayout);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryRemoteAddressNV(device, pMemoryGetRemoteAddressInfo, pAddress);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetPipelinePropertiesEXT(device, pPipelineInfo, pPipelineProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPatchControlPointsEXT(commandBuffer, patchControlPoints);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRasterizerDiscardEnableEXT(commandBuffer, rasterizerDiscardEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthBiasEnableEXT(commandBuffer, depthBiasEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLogicOpEXT(commandBuffer, logicOp);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartEnableEXT(commandBuffer, primitiveRestartEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetColorWriteEnableEXT(commandBuffer, attachmentCount, pColorWriteEnables);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMultiEXT(commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMultiIndexedEXT(commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateMicromapEXT(device, pCreateInfo, pAllocator, pMicromap);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyMicromapEXT(device, micromap, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildMicromapsEXT(commandBuffer, infoCount, pInfos);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BuildMicromapsEXT(device, deferredOperation, infoCount, pInfos);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMicromapEXT(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMicromapToMemoryEXT(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMemoryToMicromapEXT(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WriteMicromapsPropertiesEXT(device, micromapCount, pMicromaps, queryType, dataSize, pData, stride);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMicromapEXT(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMicromapToMemoryEXT(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryToMicromapEXT(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteMicromapsPropertiesEXT(commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT(device, pVersionInfo, pCompatibility);
}
VKAPI_ATTR void VKAPI_CALL vkGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) {
    // pad: mutex


    device_dispatch_table(device)->GetMicromapBuildSizesEXT(device, buildType, pBuildInfo, pSizeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawClusterHUAWEI(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawClusterIndirectHUAWEI(commandBuffer, buffer, offset);
}
VKAPI_ATTR void VKAPI_CALL vkSetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) {
    // pad: mutex


    device_dispatch_table(device)->SetDeviceMemoryPriorityEXT(device, memory, priority);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDispatchParametersARM(VkCommandBuffer commandBuffer, const VkDispatchParametersARM* pDispatchParameters) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDispatchParametersARM(commandBuffer, pDispatchParameters);
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE(device, pBindingReference, pHostMapping);
}
VKAPI_ATTR void VKAPI_CALL vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) {
    // pad: mutex


    device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE(device, descriptorSet, ppData);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryToImageIndirectNV(commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDecompressMemoryNV(commandBuffer, decompressRegionCount, pDecompressMemoryRegions);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDecompressMemoryIndirectCountNV(commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
VKAPI_ATTR void VKAPI_CALL vkGetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV(device, pCreateInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdUpdatePipelineIndirectBufferNV(commandBuffer, pipelineBindPoint, pipeline);
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) {
    // pad: mutex


    VkDeviceAddress result = device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV(device, pInfo);
    return result;
}
#if defined(VK_USE_PLATFORM_OHOS)
VKAPI_ATTR VkResult VKAPI_CALL vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetNativeBufferPropertiesOHOS(device, buffer, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryNativeBufferOHOS(device, pInfo, pBuffer);
    return result;
}
#endif  // VK_USE_PLATFORM_OHOS
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthClampEnableEXT(commandBuffer, depthClampEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPolygonModeEXT(commandBuffer, polygonMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRasterizationSamplesEXT(commandBuffer, rasterizationSamples);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetSampleMaskEXT(commandBuffer, samples, pSampleMask);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetAlphaToCoverageEnableEXT(commandBuffer, alphaToCoverageEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetAlphaToOneEnableEXT(commandBuffer, alphaToOneEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLogicOpEnableEXT(commandBuffer, logicOpEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetColorBlendEnableEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetColorBlendEquationEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetColorWriteMaskEXT(commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetTessellationDomainOriginEXT(commandBuffer, domainOrigin);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRasterizationStreamEXT(commandBuffer, rasterizationStream);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetConservativeRasterizationModeEXT(commandBuffer, conservativeRasterizationMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetExtraPrimitiveOverestimationSizeEXT(commandBuffer, extraPrimitiveOverestimationSize);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthClipEnableEXT(commandBuffer, depthClipEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetSampleLocationsEnableEXT(commandBuffer, sampleLocationsEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetColorBlendAdvancedEXT(commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetProvokingVertexModeEXT(commandBuffer, provokingVertexMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineRasterizationModeEXT(commandBuffer, lineRasterizationMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetLineStippleEnableEXT(commandBuffer, stippledLineEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthClipNegativeOneToOneEXT(commandBuffer, negativeOneToOne);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportWScalingEnableNV(commandBuffer, viewportWScalingEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetViewportSwizzleNV(commandBuffer, firstViewport, viewportCount, pViewportSwizzles);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorEnableNV(commandBuffer, coverageToColorEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageToColorLocationNV(commandBuffer, coverageToColorLocation);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationModeNV(commandBuffer, coverageModulationMode);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableEnableNV(commandBuffer, coverageModulationTableEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageModulationTableNV(commandBuffer, coverageModulationTableCount, pCoverageModulationTable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetShadingRateImageEnableNV(commandBuffer, shadingRateImageEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRepresentativeFragmentTestEnableNV(commandBuffer, representativeFragmentTestEnable);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetCoverageReductionModeNV(commandBuffer, coverageReductionMode);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateTensorARM(device, pCreateInfo, pAllocator, pTensor);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyTensorARM(device, tensor, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateTensorViewARM(device, pCreateInfo, pAllocator, pView);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyTensorViewARM(device, tensorView, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkGetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindTensorMemoryARM(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceTensorMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyTensorARM(commandBuffer, pCopyTensorInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetTensorOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetTensorViewOpaqueCaptureDescriptorDataARM(device, pInfo, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) {
    // pad: mutex


    device_dispatch_table(device)->GetShaderModuleIdentifierEXT(device, shaderModule, pIdentifier);
}
VKAPI_ATTR void VKAPI_CALL vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) {
    // pad: mutex


    device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT(device, pCreateInfo, pIdentifier);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateOpticalFlowSessionNV(device, pCreateInfo, pAllocator, pSession);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyOpticalFlowSessionNV(device, session, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindOpticalFlowSessionImageNV(device, session, bindingPoint, view, layout);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdOpticalFlowExecuteNV(commandBuffer, session, pExecuteInfo);
}
VKAPI_ATTR void VKAPI_CALL vkAntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) {
    // pad: mutex


    device_dispatch_table(device)->AntiLagUpdateAMD(device, pData);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateShadersEXT(device, createInfoCount, pCreateInfos, pAllocator, pShaders);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyShaderEXT(device, shader, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetShaderBinaryDataEXT(device, shader, pDataSize, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindShadersEXT(commandBuffer, stageCount, pStages, pShaders);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetDepthClampRangeEXT(commandBuffer, depthClampMode, pDepthClampRange);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM(device, framebuffer, pPropertiesCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM(device, pRenderingInfo, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->ConvertCooperativeVectorMatrixNV(device, pInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdConvertCooperativeVectorMatrixNV(commandBuffer, infoCount, pInfos);
}
VKAPI_ATTR VkResult VKAPI_CALL vkSetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->SetLatencySleepModeNV(device, swapchain, pSleepModeInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->LatencySleepNV(device, swapchain, pSleepInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkSetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
    // pad: mutex


    device_dispatch_table(device)->SetLatencyMarkerNV(device, swapchain, pLatencyMarkerInfo);
}
VKAPI_ATTR void VKAPI_CALL vkGetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) {
    // pad: mutex


    device_dispatch_table(device)->GetLatencyTimingsNV(device, swapchain, pLatencyMarkerInfo);
}
VKAPI_ATTR void VKAPI_CALL vkQueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) {
    // pad: mutex


    device_dispatch_table(queue)->QueueNotifyOutOfBandNV(queue, pQueueTypeInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDataGraphPipelinesARM(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateDataGraphPipelineSessionARM(device, pCreateInfo, pAllocator, pSession);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDataGraphPipelineSessionBindPointRequirementsARM(device, pInfo, pBindPointRequirementCount, pBindPointRequirements);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkGetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetDataGraphPipelineSessionMemoryRequirementsARM(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BindDataGraphPipelineSessionMemoryARM(device, bindInfoCount, pBindInfos);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyDataGraphPipelineSessionARM(device, session, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDispatchDataGraphARM(commandBuffer, session, pInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDataGraphPipelineAvailablePropertiesARM(device, pPipelineInfo, pPropertiesCount, pProperties);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetDataGraphPipelinePropertiesARM(device, pPipelineInfo, propertiesCount, pProperties);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetAttachmentFeedbackLoopEnableEXT(commandBuffer, aspectMask);
}
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
VKAPI_ATTR VkResult VKAPI_CALL vkGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetScreenBufferPropertiesQNX(device, buffer, pProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_SCREEN_QNX
VKAPI_ATTR void VKAPI_CALL vkCmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBindTileMemoryQCOM(commandBuffer, pTileMemoryBindInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryEXT(VkCommandBuffer commandBuffer, const VkDecompressMemoryInfoEXT* pDecompressMemoryInfoEXT) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDecompressMemoryEXT(commandBuffer, pDecompressMemoryInfoEXT);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDecompressMemoryIndirectCountEXT(VkCommandBuffer commandBuffer, VkMemoryDecompressionMethodFlagsEXT decompressionMethod, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDecompressMemoryIndirectCountEXT(commandBuffer, decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateExternalComputeQueueNV(device, pCreateInfo, pAllocator, pExternalQueue);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyExternalComputeQueueNV(device, externalQueue, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkGetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV* params, void* pData) {
    // pad: mutex


    device_dispatch_table(externalQueue)->GetExternalComputeQueueDataNV(externalQueue, params, pData);
}
VKAPI_ATTR void VKAPI_CALL vkGetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    // pad: mutex


    device_dispatch_table(device)->GetClusterAccelerationStructureBuildSizesNV(device, pInfo, pSizeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildClusterAccelerationStructureIndirectNV(commandBuffer, pCommandInfos);
}
VKAPI_ATTR void VKAPI_CALL vkGetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    // pad: mutex


    device_dispatch_table(device)->GetPartitionedAccelerationStructuresBuildSizesNV(device, pInfo, pSizeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildPartitionedAccelerationStructuresNV(commandBuffer, pBuildInfo);
}
VKAPI_ATTR void VKAPI_CALL vkGetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) {
    // pad: mutex


    device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsEXT(device, pInfo, pMemoryRequirements);
}
VKAPI_ATTR void VKAPI_CALL vkCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdPreprocessGeneratedCommandsEXT(commandBuffer, pGeneratedCommandsInfo, stateCommandBuffer);
}
VKAPI_ATTR void VKAPI_CALL vkCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdExecuteGeneratedCommandsEXT(commandBuffer, isPreprocessed, pGeneratedCommandsInfo);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateIndirectCommandsLayoutEXT(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyIndirectCommandsLayoutEXT(device, indirectCommandsLayout, pAllocator);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateIndirectExecutionSetEXT(device, pCreateInfo, pAllocator, pIndirectExecutionSet);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyIndirectExecutionSetEXT(device, indirectExecutionSet, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) {
    // pad: mutex


    device_dispatch_table(device)->UpdateIndirectExecutionSetPipelineEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
VKAPI_ATTR void VKAPI_CALL vkUpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) {
    // pad: mutex


    device_dispatch_table(device)->UpdateIndirectExecutionSetShaderEXT(device, indirectExecutionSet, executionSetWriteCount, pExecutionSetWrites);
}
#if defined(VK_USE_PLATFORM_METAL_EXT)
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryMetalHandleEXT(device, pGetMetalHandleInfo, pHandle);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetMemoryMetalHandlePropertiesEXT(device, handleType, pHandle, pMemoryMetalHandleProperties);
    return result;
}
#endif  // VK_USE_PLATFORM_METAL_EXT
VKAPI_ATTR VkResult VKAPI_CALL vkCreateShaderInstrumentationARM(VkDevice device, const VkShaderInstrumentationCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderInstrumentationARM* pInstrumentation) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateShaderInstrumentationARM(device, pCreateInfo, pAllocator, pInstrumentation);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyShaderInstrumentationARM(VkDevice device, VkShaderInstrumentationARM instrumentation, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyShaderInstrumentationARM(device, instrumentation, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginShaderInstrumentationARM(VkCommandBuffer commandBuffer, VkShaderInstrumentationARM instrumentation) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginShaderInstrumentationARM(commandBuffer, instrumentation);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndShaderInstrumentationARM(VkCommandBuffer commandBuffer) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndShaderInstrumentationARM(commandBuffer);
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetShaderInstrumentationValuesARM(VkDevice device, VkShaderInstrumentationARM instrumentation, uint32_t* pMetricBlockCount, void* pMetricValues, VkShaderInstrumentationValuesFlagsARM flags) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetShaderInstrumentationValuesARM(device, instrumentation, pMetricBlockCount, pMetricValues, flags);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkClearShaderInstrumentationMetricsARM(VkDevice device, VkShaderInstrumentationARM instrumentation) {
    // pad: mutex


    device_dispatch_table(device)->ClearShaderInstrumentationMetricsARM(device, instrumentation);
}
VKAPI_ATTR void VKAPI_CALL vkCmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdEndRendering2EXT(commandBuffer, pRenderingEndInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBeginCustomResolveEXT(VkCommandBuffer commandBuffer, const VkBeginCustomResolveInfoEXT* pBeginCustomResolveInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBeginCustomResolveEXT(commandBuffer, pBeginCustomResolveInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetComputeOccupancyPriorityNV(VkCommandBuffer commandBuffer, const VkComputeOccupancyPriorityParametersNV* pParameters) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetComputeOccupancyPriorityNV(commandBuffer, pParameters);
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetPrimitiveRestartIndexEXT(VkCommandBuffer commandBuffer, uint32_t primitiveRestartIndex) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetPrimitiveRestartIndexEXT(commandBuffer, primitiveRestartIndex);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateAccelerationStructureKHR(device, pCreateInfo, pAllocator, pAccelerationStructure);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) {
    // pad: mutex


    device_dispatch_table(device)->DestroyAccelerationStructureKHR(device, accelerationStructure, pAllocator);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}
VKAPI_ATTR void VKAPI_CALL vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdBuildAccelerationStructuresIndirectKHR(commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts);
}
VKAPI_ATTR VkResult VKAPI_CALL vkBuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->BuildAccelerationStructuresKHR(device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureKHR(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR(device, deferredOperation, pInfo);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR(device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureKHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyAccelerationStructureToMemoryKHR(commandBuffer, pInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdCopyMemoryToAccelerationStructureKHR(commandBuffer, pInfo);
}
VKAPI_ATTR VkDeviceAddress VKAPI_CALL vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) {
    // pad: mutex


    VkDeviceAddress result = device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR(device, pInfo);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdWriteAccelerationStructuresPropertiesKHR(commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}
VKAPI_ATTR void VKAPI_CALL vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) {
    // pad: mutex


    device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR(device, pVersionInfo, pCompatibility);
}
VKAPI_ATTR void VKAPI_CALL vkGetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) {
    // pad: mutex


    device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR(device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo);
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdTraceRaysKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth);
}
VKAPI_ATTR VkResult VKAPI_CALL vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->CreateRayTracingPipelinesKHR(device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
    return result;
}
VKAPI_ATTR VkResult VKAPI_CALL vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) {
    // pad: mutex


    VkResult result = device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR(device, pipeline, firstGroup, groupCount, dataSize, pData);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdTraceRaysIndirectKHR(commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress);
}
VKAPI_ATTR VkDeviceSize VKAPI_CALL vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) {
    // pad: mutex


    VkDeviceSize result = device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR(device, pipeline, group, groupShader);
    return result;
}
VKAPI_ATTR void VKAPI_CALL vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdSetRayTracingPipelineStackSizeKHR(commandBuffer, pipelineStackSize);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksEXT(commandBuffer, groupCountX, groupCountY, groupCountZ);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectEXT(commandBuffer, buffer, offset, drawCount, stride);
}
VKAPI_ATTR void VKAPI_CALL vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) {
    // pad: mutex


    device_dispatch_table(commandBuffer)->CmdDrawMeshTasksIndirectCountEXT(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_instance_functions(VkInstance instance, const char* pName) {
    if (strcmp(pName, "vkCreateInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateInstance);
    if (strcmp(pName, "vkDestroyInstance") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyInstance);
    if (strcmp(pName, "vkEnumeratePhysicalDevices") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDevices);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties);
    if (strcmp(pName, "vkGetInstanceProcAddr") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetInstanceProcAddr);
    if (strcmp(pName, "vkCreateDevice") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDevice);
    if (strcmp(pName, "vkEnumerateInstanceExtensionProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceExtensionProperties);
    if (strcmp(pName, "vkEnumerateInstanceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateInstanceLayerProperties);
    if (strcmp(pName, "vkEnumerateDeviceLayerProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumerateDeviceLayerProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceGroups") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroups);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalBufferProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalFenceProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFenceProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalSemaphoreProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (strcmp(pName, "vkGetPhysicalDeviceToolProperties") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolProperties);
    if (strcmp(pName, "vkDestroySurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySurfaceKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceSupportKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceFormatsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (strcmp(pName, "vkGetPhysicalDevicePresentRectanglesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDevicePresentRectanglesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (strcmp(pName, "vkGetDisplayPlaneSupportedDisplaysKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneSupportedDisplaysKHR);
    if (strcmp(pName, "vkGetDisplayModePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModePropertiesKHR);
    if (strcmp(pName, "vkCreateDisplayModeKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayModeKHR);
    if (strcmp(pName, "vkGetDisplayPlaneCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilitiesKHR);
    if (strcmp(pName, "vkCreateDisplayPlaneSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDisplayPlaneSurfaceKHR);
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    if (strcmp(pName, "vkCreateXlibSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXlibSurfaceKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceXlibPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXlibPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_XLIB_KHR
#if defined(VK_USE_PLATFORM_XCB_KHR)
    if (strcmp(pName, "vkCreateXcbSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateXcbSurfaceKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceXcbPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceXcbPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_XCB_KHR
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    if (strcmp(pName, "vkCreateWaylandSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWaylandSurfaceKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceWaylandPresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWaylandPresentationSupportKHR);
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if (strcmp(pName, "vkCreateAndroidSurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAndroidSurfaceKHR);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkCreateWin32SurfaceKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateWin32SurfaceKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceWin32PresentationSupportKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceWin32PresentationSupportKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkGetPhysicalDeviceVideoCapabilitiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoCapabilitiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceVideoFormatPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoFormatPropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceFeatures2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFeatures2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFormatProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceMemoryProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMemoryProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceGroupsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceGroupsKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalBufferPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceExternalFencePropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceFormats2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayProperties2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (strcmp(pName, "vkGetDisplayModeProperties2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayModeProperties2KHR);
    if (strcmp(pName, "vkGetDisplayPlaneCapabilities2KHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDisplayPlaneCapabilities2KHR);
    if (strcmp(pName, "vkGetPhysicalDeviceFragmentShadingRatesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceFragmentShadingRatesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR);
    if (strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsKHR);
    if (strcmp(pName, "vkCreateDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugReportCallbackEXT);
    if (strcmp(pName, "vkDestroyDebugReportCallbackEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugReportCallbackEXT);
    if (strcmp(pName, "vkDebugReportMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugReportMessageEXT);
#if defined(VK_USE_PLATFORM_GGP)
    if (strcmp(pName, "vkCreateStreamDescriptorSurfaceGGP") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateStreamDescriptorSurfaceGGP);
#endif  // VK_USE_PLATFORM_GGP
    if (strcmp(pName, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
#if defined(VK_USE_PLATFORM_VI_NN)
    if (strcmp(pName, "vkCreateViSurfaceNN") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateViSurfaceNN);
#endif  // VK_USE_PLATFORM_VI_NN
    if (strcmp(pName, "vkReleaseDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseDisplayEXT);
#if defined(VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    if (strcmp(pName, "vkAcquireXlibDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireXlibDisplayEXT);
    if (strcmp(pName, "vkGetRandROutputDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRandROutputDisplayEXT);
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    if (strcmp(pName, "vkGetPhysicalDeviceSurfaceCapabilities2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfaceCapabilities2EXT);
#if defined(VK_USE_PLATFORM_IOS_MVK)
    if (strcmp(pName, "vkCreateIOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIOSSurfaceMVK);
#endif  // VK_USE_PLATFORM_IOS_MVK
#if defined(VK_USE_PLATFORM_MACOS_MVK)
    if (strcmp(pName, "vkCreateMacOSSurfaceMVK") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMacOSSurfaceMVK);
#endif  // VK_USE_PLATFORM_MACOS_MVK
    if (strcmp(pName, "vkSetDebugUtilsObjectNameEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectNameEXT);
    if (strcmp(pName, "vkSetDebugUtilsObjectTagEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectTagEXT);
    if (strcmp(pName, "vkQueueBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBeginDebugUtilsLabelEXT);
    if (strcmp(pName, "vkQueueEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueEndDebugUtilsLabelEXT);
    if (strcmp(pName, "vkQueueInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueInsertDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdBeginDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdEndDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdInsertDebugUtilsLabelEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInsertDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCreateDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDebugUtilsMessengerEXT);
    if (strcmp(pName, "vkDestroyDebugUtilsMessengerEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDebugUtilsMessengerEXT);
    if (strcmp(pName, "vkSubmitDebugUtilsMessageEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkSubmitDebugUtilsMessageEXT);
    if (strcmp(pName, "vkGetPhysicalDeviceDescriptorSizeEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDescriptorSizeEXT);
    if (strcmp(pName, "vkGetPhysicalDeviceMultisamplePropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (strcmp(pName, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCalibrateableTimeDomainsEXT);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if (strcmp(pName, "vkCreateImagePipeSurfaceFUCHSIA") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImagePipeSurfaceFUCHSIA);
#endif  // VK_USE_PLATFORM_FUCHSIA
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkCreateMetalSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMetalSurfaceEXT);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkGetPhysicalDeviceToolPropertiesEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceToolPropertiesEXT);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixPropertiesNV);
    if (strcmp(pName, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetPhysicalDeviceSurfacePresentModes2EXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceSurfacePresentModes2EXT);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCreateHeadlessSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateHeadlessSurfaceEXT);
    if (strcmp(pName, "vkAcquireDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireDrmDisplayEXT);
    if (strcmp(pName, "vkGetDrmDisplayEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDrmDisplayEXT);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkAcquireWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireWinrtDisplayNV);
    if (strcmp(pName, "vkGetWinrtDisplayNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetWinrtDisplayNV);
#endif  // VK_USE_PLATFORM_WIN32_KHR
#if defined(VK_USE_PLATFORM_DIRECTFB_EXT)
    if (strcmp(pName, "vkCreateDirectFBSurfaceEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDirectFBSurfaceEXT);
    if (strcmp(pName, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceDirectFBPresentationSupportEXT);
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if (strcmp(pName, "vkCreateScreenSurfaceQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateScreenSurfaceQNX);
    if (strcmp(pName, "vkGetPhysicalDeviceScreenPresentationSupportQNX") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceScreenPresentationSupportQNX);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    if (strcmp(pName, "vkGetPhysicalDeviceExternalTensorPropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceExternalTensorPropertiesARM);
    if (strcmp(pName, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceOpticalFlowImageFormatsNV);
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeVectorPropertiesNV);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM);
#if defined(VK_USE_PLATFORM_OHOS)
    if (strcmp(pName, "vkCreateSurfaceOHOS") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSurfaceOHOS);
#endif  // VK_USE_PLATFORM_OHOS
    if (strcmp(pName, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM);
    if (strcmp(pName, "vkEnumeratePhysicalDeviceShaderInstrumentationMetricsARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkEnumeratePhysicalDeviceShaderInstrumentationMetricsARM);
    if (strcmp(pName, "vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM);
#if defined(VK_USE_PLATFORM_UBM_SEC)
    if (strcmp(pName, "vkCreateUbmSurfaceSEC") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateUbmSurfaceSEC);
    if (strcmp(pName, "vkGetPhysicalDeviceUbmPresentationSupportSEC") == 0)
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPhysicalDeviceUbmPresentationSupportSEC);
#endif  // VK_USE_PLATFORM_UBM_SEC

    return nullptr;
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL api_dump_known_device_functions(VkDevice device, const char* pName) {
    if (strcmp(pName, "vkGetDeviceProcAddr") == 0 && (!device || device_dispatch_table(device)->GetDeviceProcAddr))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceProcAddr);
    if (strcmp(pName, "vkDestroyDevice") == 0 && (!device || device_dispatch_table(device)->DestroyDevice))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDevice);
    if (strcmp(pName, "vkGetDeviceQueue") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue);
    if (strcmp(pName, "vkQueueSubmit") == 0 && (!device || device_dispatch_table(device)->QueueSubmit))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit);
    if (strcmp(pName, "vkQueueWaitIdle") == 0 && (!device || device_dispatch_table(device)->QueueWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueWaitIdle);
    if (strcmp(pName, "vkDeviceWaitIdle") == 0 && (!device || device_dispatch_table(device)->DeviceWaitIdle))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeviceWaitIdle);
    if (strcmp(pName, "vkAllocateMemory") == 0 && (!device || device_dispatch_table(device)->AllocateMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateMemory);
    if (strcmp(pName, "vkFreeMemory") == 0 && (!device || device_dispatch_table(device)->FreeMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeMemory);
    if (strcmp(pName, "vkMapMemory") == 0 && (!device || device_dispatch_table(device)->MapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory);
    if (strcmp(pName, "vkUnmapMemory") == 0 && (!device || device_dispatch_table(device)->UnmapMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory);
    if (strcmp(pName, "vkFlushMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->FlushMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFlushMappedMemoryRanges);
    if (strcmp(pName, "vkInvalidateMappedMemoryRanges") == 0 && (!device || device_dispatch_table(device)->InvalidateMappedMemoryRanges))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInvalidateMappedMemoryRanges);
    if (strcmp(pName, "vkGetDeviceMemoryCommitment") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryCommitment))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryCommitment);
    if (strcmp(pName, "vkBindBufferMemory") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory);
    if (strcmp(pName, "vkBindImageMemory") == 0 && (!device || device_dispatch_table(device)->BindImageMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory);
    if (strcmp(pName, "vkGetBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements);
    if (strcmp(pName, "vkGetImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements);
    if (strcmp(pName, "vkQueueBindSparse") == 0 && (!device || device_dispatch_table(device)->QueueBindSparse))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBindSparse);
    if (strcmp(pName, "vkCreateFence") == 0 && (!device || device_dispatch_table(device)->CreateFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFence);
    if (strcmp(pName, "vkDestroyFence") == 0 && (!device || device_dispatch_table(device)->DestroyFence))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFence);
    if (strcmp(pName, "vkResetFences") == 0 && (!device || device_dispatch_table(device)->ResetFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetFences);
    if (strcmp(pName, "vkGetFenceStatus") == 0 && (!device || device_dispatch_table(device)->GetFenceStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceStatus);
    if (strcmp(pName, "vkWaitForFences") == 0 && (!device || device_dispatch_table(device)->WaitForFences))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForFences);
    if (strcmp(pName, "vkCreateSemaphore") == 0 && (!device || device_dispatch_table(device)->CreateSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSemaphore);
    if (strcmp(pName, "vkDestroySemaphore") == 0 && (!device || device_dispatch_table(device)->DestroySemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySemaphore);
    if (strcmp(pName, "vkCreateQueryPool") == 0 && (!device || device_dispatch_table(device)->CreateQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateQueryPool);
    if (strcmp(pName, "vkDestroyQueryPool") == 0 && (!device || device_dispatch_table(device)->DestroyQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyQueryPool);
    if (strcmp(pName, "vkGetQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->GetQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueryPoolResults);
    if (strcmp(pName, "vkCreateBuffer") == 0 && (!device || device_dispatch_table(device)->CreateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBuffer);
    if (strcmp(pName, "vkDestroyBuffer") == 0 && (!device || device_dispatch_table(device)->DestroyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBuffer);
    if (strcmp(pName, "vkCreateImage") == 0 && (!device || device_dispatch_table(device)->CreateImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImage);
    if (strcmp(pName, "vkDestroyImage") == 0 && (!device || device_dispatch_table(device)->DestroyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImage);
    if (strcmp(pName, "vkGetImageSubresourceLayout") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout);
    if (strcmp(pName, "vkCreateImageView") == 0 && (!device || device_dispatch_table(device)->CreateImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateImageView);
    if (strcmp(pName, "vkDestroyImageView") == 0 && (!device || device_dispatch_table(device)->DestroyImageView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyImageView);
    if (strcmp(pName, "vkCreateCommandPool") == 0 && (!device || device_dispatch_table(device)->CreateCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCommandPool);
    if (strcmp(pName, "vkDestroyCommandPool") == 0 && (!device || device_dispatch_table(device)->DestroyCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCommandPool);
    if (strcmp(pName, "vkResetCommandPool") == 0 && (!device || device_dispatch_table(device)->ResetCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandPool);
    if (strcmp(pName, "vkAllocateCommandBuffers") == 0 && (!device || device_dispatch_table(device)->AllocateCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateCommandBuffers);
    if (strcmp(pName, "vkFreeCommandBuffers") == 0 && (!device || device_dispatch_table(device)->FreeCommandBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeCommandBuffers);
    if (strcmp(pName, "vkBeginCommandBuffer") == 0 && (!device || device_dispatch_table(device)->BeginCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBeginCommandBuffer);
    if (strcmp(pName, "vkEndCommandBuffer") == 0 && (!device || device_dispatch_table(device)->EndCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkEndCommandBuffer);
    if (strcmp(pName, "vkResetCommandBuffer") == 0 && (!device || device_dispatch_table(device)->ResetCommandBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetCommandBuffer);
    if (strcmp(pName, "vkCmdCopyBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer);
    if (strcmp(pName, "vkCmdCopyImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage);
    if (strcmp(pName, "vkCmdCopyBufferToImage") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage);
    if (strcmp(pName, "vkCmdCopyImageToBuffer") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer);
    if (strcmp(pName, "vkCmdUpdateBuffer") == 0 && (!device || device_dispatch_table(device)->CmdUpdateBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdateBuffer);
    if (strcmp(pName, "vkCmdFillBuffer") == 0 && (!device || device_dispatch_table(device)->CmdFillBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdFillBuffer);
    if (strcmp(pName, "vkCmdPipelineBarrier") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier);
    if (strcmp(pName, "vkCmdBeginQuery") == 0 && (!device || device_dispatch_table(device)->CmdBeginQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQuery);
    if (strcmp(pName, "vkCmdEndQuery") == 0 && (!device || device_dispatch_table(device)->CmdEndQuery))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQuery);
    if (strcmp(pName, "vkCmdResetQueryPool") == 0 && (!device || device_dispatch_table(device)->CmdResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetQueryPool);
    if (strcmp(pName, "vkCmdWriteTimestamp") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp);
    if (strcmp(pName, "vkCmdCopyQueryPoolResults") == 0 && (!device || device_dispatch_table(device)->CmdCopyQueryPoolResults))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyQueryPoolResults);
    if (strcmp(pName, "vkCmdExecuteCommands") == 0 && (!device || device_dispatch_table(device)->CmdExecuteCommands))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteCommands);
    if (strcmp(pName, "vkCreateEvent") == 0 && (!device || device_dispatch_table(device)->CreateEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateEvent);
    if (strcmp(pName, "vkDestroyEvent") == 0 && (!device || device_dispatch_table(device)->DestroyEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyEvent);
    if (strcmp(pName, "vkGetEventStatus") == 0 && (!device || device_dispatch_table(device)->GetEventStatus))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEventStatus);
    if (strcmp(pName, "vkSetEvent") == 0 && (!device || device_dispatch_table(device)->SetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetEvent);
    if (strcmp(pName, "vkResetEvent") == 0 && (!device || device_dispatch_table(device)->ResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetEvent);
    if (strcmp(pName, "vkCreateBufferView") == 0 && (!device || device_dispatch_table(device)->CreateBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferView);
    if (strcmp(pName, "vkDestroyBufferView") == 0 && (!device || device_dispatch_table(device)->DestroyBufferView))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferView);
    if (strcmp(pName, "vkCreateShaderModule") == 0 && (!device || device_dispatch_table(device)->CreateShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShaderModule);
    if (strcmp(pName, "vkDestroyShaderModule") == 0 && (!device || device_dispatch_table(device)->DestroyShaderModule))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderModule);
    if (strcmp(pName, "vkCreatePipelineCache") == 0 && (!device || device_dispatch_table(device)->CreatePipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineCache);
    if (strcmp(pName, "vkDestroyPipelineCache") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineCache))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineCache);
    if (strcmp(pName, "vkGetPipelineCacheData") == 0 && (!device || device_dispatch_table(device)->GetPipelineCacheData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineCacheData);
    if (strcmp(pName, "vkMergePipelineCaches") == 0 && (!device || device_dispatch_table(device)->MergePipelineCaches))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergePipelineCaches);
    if (strcmp(pName, "vkCreateComputePipelines") == 0 && (!device || device_dispatch_table(device)->CreateComputePipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateComputePipelines);
    if (strcmp(pName, "vkDestroyPipeline") == 0 && (!device || device_dispatch_table(device)->DestroyPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipeline);
    if (strcmp(pName, "vkCreatePipelineLayout") == 0 && (!device || device_dispatch_table(device)->CreatePipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineLayout);
    if (strcmp(pName, "vkDestroyPipelineLayout") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineLayout);
    if (strcmp(pName, "vkCreateSampler") == 0 && (!device || device_dispatch_table(device)->CreateSampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSampler);
    if (strcmp(pName, "vkDestroySampler") == 0 && (!device || device_dispatch_table(device)->DestroySampler))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySampler);
    if (strcmp(pName, "vkCreateDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorSetLayout);
    if (strcmp(pName, "vkDestroyDescriptorSetLayout") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorSetLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorSetLayout);
    if (strcmp(pName, "vkCreateDescriptorPool") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorPool);
    if (strcmp(pName, "vkDestroyDescriptorPool") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorPool);
    if (strcmp(pName, "vkResetDescriptorPool") == 0 && (!device || device_dispatch_table(device)->ResetDescriptorPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetDescriptorPool);
    if (strcmp(pName, "vkAllocateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->AllocateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAllocateDescriptorSets);
    if (strcmp(pName, "vkFreeDescriptorSets") == 0 && (!device || device_dispatch_table(device)->FreeDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkFreeDescriptorSets);
    if (strcmp(pName, "vkUpdateDescriptorSets") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSets);
    if (strcmp(pName, "vkCmdBindPipeline") == 0 && (!device || device_dispatch_table(device)->CmdBindPipeline))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipeline);
    if (strcmp(pName, "vkCmdBindDescriptorSets") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets);
    if (strcmp(pName, "vkCmdClearColorImage") == 0 && (!device || device_dispatch_table(device)->CmdClearColorImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearColorImage);
    if (strcmp(pName, "vkCmdDispatch") == 0 && (!device || device_dispatch_table(device)->CmdDispatch))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatch);
    if (strcmp(pName, "vkCmdDispatchIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDispatchIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchIndirect);
    if (strcmp(pName, "vkCmdSetEvent") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent);
    if (strcmp(pName, "vkCmdResetEvent") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent);
    if (strcmp(pName, "vkCmdWaitEvents") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents);
    if (strcmp(pName, "vkCmdPushConstants") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants);
    if (strcmp(pName, "vkCreateGraphicsPipelines") == 0 && (!device || device_dispatch_table(device)->CreateGraphicsPipelines))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateGraphicsPipelines);
    if (strcmp(pName, "vkCreateFramebuffer") == 0 && (!device || device_dispatch_table(device)->CreateFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateFramebuffer);
    if (strcmp(pName, "vkDestroyFramebuffer") == 0 && (!device || device_dispatch_table(device)->DestroyFramebuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyFramebuffer);
    if (strcmp(pName, "vkCreateRenderPass") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass);
    if (strcmp(pName, "vkDestroyRenderPass") == 0 && (!device || device_dispatch_table(device)->DestroyRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyRenderPass);
    if (strcmp(pName, "vkGetRenderAreaGranularity") == 0 && (!device || device_dispatch_table(device)->GetRenderAreaGranularity))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderAreaGranularity);
    if (strcmp(pName, "vkCmdSetViewport") == 0 && (!device || device_dispatch_table(device)->CmdSetViewport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewport);
    if (strcmp(pName, "vkCmdSetScissor") == 0 && (!device || device_dispatch_table(device)->CmdSetScissor))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissor);
    if (strcmp(pName, "vkCmdSetLineWidth") == 0 && (!device || device_dispatch_table(device)->CmdSetLineWidth))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineWidth);
    if (strcmp(pName, "vkCmdSetDepthBias") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias);
    if (strcmp(pName, "vkCmdSetBlendConstants") == 0 && (!device || device_dispatch_table(device)->CmdSetBlendConstants))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetBlendConstants);
    if (strcmp(pName, "vkCmdSetDepthBounds") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBounds))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBounds);
    if (strcmp(pName, "vkCmdSetStencilCompareMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilCompareMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilCompareMask);
    if (strcmp(pName, "vkCmdSetStencilWriteMask") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilWriteMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilWriteMask);
    if (strcmp(pName, "vkCmdSetStencilReference") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilReference))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilReference);
    if (strcmp(pName, "vkCmdBindIndexBuffer") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer);
    if (strcmp(pName, "vkCmdBindVertexBuffers") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers);
    if (strcmp(pName, "vkCmdDraw") == 0 && (!device || device_dispatch_table(device)->CmdDraw))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDraw);
    if (strcmp(pName, "vkCmdDrawIndexed") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexed))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexed);
    if (strcmp(pName, "vkCmdDrawIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirect);
    if (strcmp(pName, "vkCmdDrawIndexedIndirect") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirect))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirect);
    if (strcmp(pName, "vkCmdBlitImage") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage);
    if (strcmp(pName, "vkCmdClearDepthStencilImage") == 0 && (!device || device_dispatch_table(device)->CmdClearDepthStencilImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearDepthStencilImage);
    if (strcmp(pName, "vkCmdClearAttachments") == 0 && (!device || device_dispatch_table(device)->CmdClearAttachments))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdClearAttachments);
    if (strcmp(pName, "vkCmdResolveImage") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage);
    if (strcmp(pName, "vkCmdBeginRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass);
    if (strcmp(pName, "vkCmdNextSubpass") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass);
    if (strcmp(pName, "vkCmdEndRenderPass") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass);
    if (strcmp(pName, "vkBindBufferMemory2") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2);
    if (strcmp(pName, "vkBindImageMemory2") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2);
    if (strcmp(pName, "vkGetDeviceGroupPeerMemoryFeatures") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeatures))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeatures);
    if (strcmp(pName, "vkCmdSetDeviceMask") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMask))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMask);
    if (strcmp(pName, "vkGetImageMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2);
    if (strcmp(pName, "vkGetBufferMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements2") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2);
    if (strcmp(pName, "vkTrimCommandPool") == 0 && (!device || device_dispatch_table(device)->TrimCommandPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPool);
    if (strcmp(pName, "vkGetDeviceQueue2") == 0 && (!device || device_dispatch_table(device)->GetDeviceQueue2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceQueue2);
    if (strcmp(pName, "vkCmdDispatchBase") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBase))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBase);
    if (strcmp(pName, "vkCreateDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplate);
    if (strcmp(pName, "vkDestroyDescriptorUpdateTemplate") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplate);
    if (strcmp(pName, "vkUpdateDescriptorSetWithTemplate") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplate);
    if (strcmp(pName, "vkGetDescriptorSetLayoutSupport") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupport))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupport);
    if (strcmp(pName, "vkCreateSamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversion);
    if (strcmp(pName, "vkDestroySamplerYcbcrConversion") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversion))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversion);
    if (strcmp(pName, "vkResetQueryPool") == 0 && (!device || device_dispatch_table(device)->ResetQueryPool))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPool);
    if (strcmp(pName, "vkGetSemaphoreCounterValue") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValue))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValue);
    if (strcmp(pName, "vkWaitSemaphores") == 0 && (!device || device_dispatch_table(device)->WaitSemaphores))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphores);
    if (strcmp(pName, "vkSignalSemaphore") == 0 && (!device || device_dispatch_table(device)->SignalSemaphore))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphore);
    if (strcmp(pName, "vkGetBufferDeviceAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddress);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddress);
    if (strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddress") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddress))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddress);
    if (strcmp(pName, "vkCmdDrawIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCount);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCount") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCount);
    if (strcmp(pName, "vkCreateRenderPass2") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2);
    if (strcmp(pName, "vkCmdBeginRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2);
    if (strcmp(pName, "vkCmdNextSubpass2") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2);
    if (strcmp(pName, "vkCmdEndRenderPass2") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2);
    if (strcmp(pName, "vkCreatePrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlot);
    if (strcmp(pName, "vkDestroyPrivateDataSlot") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlot))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlot);
    if (strcmp(pName, "vkSetPrivateData") == 0 && (!device || device_dispatch_table(device)->SetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateData);
    if (strcmp(pName, "vkGetPrivateData") == 0 && (!device || device_dispatch_table(device)->GetPrivateData))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateData);
    if (strcmp(pName, "vkCmdPipelineBarrier2") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2);
    if (strcmp(pName, "vkCmdWriteTimestamp2") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2);
    if (strcmp(pName, "vkQueueSubmit2") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2);
    if (strcmp(pName, "vkCmdCopyBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2);
    if (strcmp(pName, "vkCmdCopyImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2);
    if (strcmp(pName, "vkCmdCopyBufferToImage2") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2);
    if (strcmp(pName, "vkCmdCopyImageToBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2);
    if (strcmp(pName, "vkGetDeviceBufferMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirements);
    if (strcmp(pName, "vkGetDeviceImageMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirements);
    if (strcmp(pName, "vkGetDeviceImageSparseMemoryRequirements") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirements))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirements);
    if (strcmp(pName, "vkCmdSetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2);
    if (strcmp(pName, "vkCmdResetEvent2") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2);
    if (strcmp(pName, "vkCmdWaitEvents2") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2);
    if (strcmp(pName, "vkCmdBlitImage2") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2);
    if (strcmp(pName, "vkCmdResolveImage2") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2);
    if (strcmp(pName, "vkCmdBeginRendering") == 0 && (!device || device_dispatch_table(device)->CmdBeginRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRendering);
    if (strcmp(pName, "vkCmdEndRendering") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering);
    if (strcmp(pName, "vkCmdSetCullMode") == 0 && (!device || device_dispatch_table(device)->CmdSetCullMode))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullMode);
    if (strcmp(pName, "vkCmdSetFrontFace") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFace))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFace);
    if (strcmp(pName, "vkCmdSetPrimitiveTopology") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopology))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopology);
    if (strcmp(pName, "vkCmdSetViewportWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCount);
    if (strcmp(pName, "vkCmdSetScissorWithCount") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCount))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCount);
    if (strcmp(pName, "vkCmdBindVertexBuffers2") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2);
    if (strcmp(pName, "vkCmdSetDepthTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnable);
    if (strcmp(pName, "vkCmdSetDepthWriteEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnable);
    if (strcmp(pName, "vkCmdSetDepthCompareOp") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOp);
    if (strcmp(pName, "vkCmdSetDepthBoundsTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnable);
    if (strcmp(pName, "vkCmdSetStencilTestEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnable);
    if (strcmp(pName, "vkCmdSetStencilOp") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOp))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOp);
    if (strcmp(pName, "vkCmdSetRasterizerDiscardEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnable);
    if (strcmp(pName, "vkCmdSetDepthBiasEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnable);
    if (strcmp(pName, "vkCmdSetPrimitiveRestartEnable") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnable))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnable);
    if (strcmp(pName, "vkMapMemory2") == 0 && (!device || device_dispatch_table(device)->MapMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory2);
    if (strcmp(pName, "vkUnmapMemory2") == 0 && (!device || device_dispatch_table(device)->UnmapMemory2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory2);
    if (strcmp(pName, "vkGetDeviceImageSubresourceLayout") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSubresourceLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSubresourceLayout);
    if (strcmp(pName, "vkGetImageSubresourceLayout2") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2);
    if (strcmp(pName, "vkCopyMemoryToImage") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToImage);
    if (strcmp(pName, "vkCopyImageToMemory") == 0 && (!device || device_dispatch_table(device)->CopyImageToMemory))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToMemory);
    if (strcmp(pName, "vkCopyImageToImage") == 0 && (!device || device_dispatch_table(device)->CopyImageToImage))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToImage);
    if (strcmp(pName, "vkTransitionImageLayout") == 0 && (!device || device_dispatch_table(device)->TransitionImageLayout))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTransitionImageLayout);
    if (strcmp(pName, "vkCmdPushDescriptorSet") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate);
    if (strcmp(pName, "vkCmdBindDescriptorSets2") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets2);
    if (strcmp(pName, "vkCmdPushConstants2") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants2);
    if (strcmp(pName, "vkCmdPushDescriptorSet2") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet2);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate2") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate2);
    if (strcmp(pName, "vkCmdSetLineStipple") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStipple))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStipple);
    if (strcmp(pName, "vkCmdBindIndexBuffer2") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer2))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer2);
    if (strcmp(pName, "vkGetRenderingAreaGranularity") == 0 && (!device || device_dispatch_table(device)->GetRenderingAreaGranularity))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderingAreaGranularity);
    if (strcmp(pName, "vkCmdSetRenderingAttachmentLocations") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingAttachmentLocations))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingAttachmentLocations);
    if (strcmp(pName, "vkCmdSetRenderingInputAttachmentIndices") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingInputAttachmentIndices))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingInputAttachmentIndices);
    if (strcmp(pName, "vkCreateSwapchainKHR") == 0 && (!device || device_dispatch_table(device)->CreateSwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSwapchainKHR);
    if (strcmp(pName, "vkDestroySwapchainKHR") == 0 && (!device || device_dispatch_table(device)->DestroySwapchainKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySwapchainKHR);
    if (strcmp(pName, "vkGetSwapchainImagesKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainImagesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainImagesKHR);
    if (strcmp(pName, "vkAcquireNextImageKHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImageKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImageKHR);
    if (strcmp(pName, "vkQueuePresentKHR") == 0 && (!device || device_dispatch_table(device)->QueuePresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueuePresentKHR);
    if (strcmp(pName, "vkGetDeviceGroupPresentCapabilitiesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPresentCapabilitiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPresentCapabilitiesKHR);
    if (strcmp(pName, "vkGetDeviceGroupSurfacePresentModesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModesKHR);
    if (strcmp(pName, "vkAcquireNextImage2KHR") == 0 && (!device || device_dispatch_table(device)->AcquireNextImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireNextImage2KHR);
    if (strcmp(pName, "vkCreateSharedSwapchainsKHR") == 0 && (!device || device_dispatch_table(device)->CreateSharedSwapchainsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSharedSwapchainsKHR);
    if (strcmp(pName, "vkCreateVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionKHR);
    if (strcmp(pName, "vkDestroyVideoSessionKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionKHR);
    if (strcmp(pName, "vkGetVideoSessionMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetVideoSessionMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetVideoSessionMemoryRequirementsKHR);
    if (strcmp(pName, "vkBindVideoSessionMemoryKHR") == 0 && (!device || device_dispatch_table(device)->BindVideoSessionMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindVideoSessionMemoryKHR);
    if (strcmp(pName, "vkCreateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->CreateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateVideoSessionParametersKHR);
    if (strcmp(pName, "vkUpdateVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->UpdateVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateVideoSessionParametersKHR);
    if (strcmp(pName, "vkDestroyVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->DestroyVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyVideoSessionParametersKHR);
    if (strcmp(pName, "vkCmdBeginVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginVideoCodingKHR);
    if (strcmp(pName, "vkCmdEndVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndVideoCodingKHR);
    if (strcmp(pName, "vkCmdControlVideoCodingKHR") == 0 && (!device || device_dispatch_table(device)->CmdControlVideoCodingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdControlVideoCodingKHR);
    if (strcmp(pName, "vkCmdDecodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdDecodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecodeVideoKHR);
    if (strcmp(pName, "vkCmdBeginRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderingKHR);
    if (strcmp(pName, "vkCmdEndRenderingKHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderingKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderingKHR);
    if (strcmp(pName, "vkGetDeviceGroupPeerMemoryFeaturesKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (strcmp(pName, "vkCmdSetDeviceMaskKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetDeviceMaskKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDeviceMaskKHR);
    if (strcmp(pName, "vkCmdDispatchBaseKHR") == 0 && (!device || device_dispatch_table(device)->CmdDispatchBaseKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchBaseKHR);
    if (strcmp(pName, "vkTrimCommandPoolKHR") == 0 && (!device || device_dispatch_table(device)->TrimCommandPoolKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTrimCommandPoolKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetMemoryWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleKHR);
    if (strcmp(pName, "vkGetMemoryWin32HandlePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandlePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandlePropertiesKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkGetMemoryFdKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdKHR);
    if (strcmp(pName, "vkGetMemoryFdPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetMemoryFdPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryFdPropertiesKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkImportSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreWin32HandleKHR);
    if (strcmp(pName, "vkGetSemaphoreWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreWin32HandleKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkImportSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreFdKHR);
    if (strcmp(pName, "vkGetSemaphoreFdKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreFdKHR);
    if (strcmp(pName, "vkCmdPushDescriptorSetKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetKHR);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplateKHR);
    if (strcmp(pName, "vkCreateDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->CreateDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDescriptorUpdateTemplateKHR);
    if (strcmp(pName, "vkDestroyDescriptorUpdateTemplateKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDescriptorUpdateTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDescriptorUpdateTemplateKHR);
    if (strcmp(pName, "vkUpdateDescriptorSetWithTemplateKHR") == 0 && (!device || device_dispatch_table(device)->UpdateDescriptorSetWithTemplateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateDescriptorSetWithTemplateKHR);
    if (strcmp(pName, "vkCreateRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CreateRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRenderPass2KHR);
    if (strcmp(pName, "vkCmdBeginRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBeginRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginRenderPass2KHR);
    if (strcmp(pName, "vkCmdNextSubpass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdNextSubpass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdNextSubpass2KHR);
    if (strcmp(pName, "vkCmdEndRenderPass2KHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRenderPass2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRenderPass2KHR);
    if (strcmp(pName, "vkGetSwapchainStatusKHR") == 0 && (!device || device_dispatch_table(device)->GetSwapchainStatusKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainStatusKHR);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkImportFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceWin32HandleKHR);
    if (strcmp(pName, "vkGetFenceWin32HandleKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceWin32HandleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceWin32HandleKHR);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkImportFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->ImportFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportFenceFdKHR);
    if (strcmp(pName, "vkGetFenceFdKHR") == 0 && (!device || device_dispatch_table(device)->GetFenceFdKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFenceFdKHR);
    if (strcmp(pName, "vkAcquireProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->AcquireProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireProfilingLockKHR);
    if (strcmp(pName, "vkReleaseProfilingLockKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseProfilingLockKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseProfilingLockKHR);
    if (strcmp(pName, "vkGetImageMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageMemoryRequirements2KHR);
    if (strcmp(pName, "vkGetBufferMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetBufferMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferMemoryRequirements2KHR);
    if (strcmp(pName, "vkGetImageSparseMemoryRequirements2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSparseMemoryRequirements2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSparseMemoryRequirements2KHR);
    if (strcmp(pName, "vkCreateSamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->CreateSamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateSamplerYcbcrConversionKHR);
    if (strcmp(pName, "vkDestroySamplerYcbcrConversionKHR") == 0 && (!device || device_dispatch_table(device)->DestroySamplerYcbcrConversionKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroySamplerYcbcrConversionKHR);
    if (strcmp(pName, "vkBindBufferMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindBufferMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindBufferMemory2KHR);
    if (strcmp(pName, "vkBindImageMemory2KHR") == 0 && (!device || device_dispatch_table(device)->BindImageMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindImageMemory2KHR);
    if (strcmp(pName, "vkGetDescriptorSetLayoutSupportKHR") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSupportKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSupportKHR);
    if (strcmp(pName, "vkCmdDrawIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountKHR);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCountKHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountKHR);
    if (strcmp(pName, "vkGetSemaphoreCounterValueKHR") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreCounterValueKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreCounterValueKHR);
    if (strcmp(pName, "vkWaitSemaphoresKHR") == 0 && (!device || device_dispatch_table(device)->WaitSemaphoresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitSemaphoresKHR);
    if (strcmp(pName, "vkSignalSemaphoreKHR") == 0 && (!device || device_dispatch_table(device)->SignalSemaphoreKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSignalSemaphoreKHR);
    if (strcmp(pName, "vkCmdSetFragmentShadingRateKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateKHR);
    if (strcmp(pName, "vkCmdSetRenderingAttachmentLocationsKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingAttachmentLocationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingAttachmentLocationsKHR);
    if (strcmp(pName, "vkCmdSetRenderingInputAttachmentIndicesKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRenderingInputAttachmentIndicesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRenderingInputAttachmentIndicesKHR);
    if (strcmp(pName, "vkWaitForPresentKHR") == 0 && (!device || device_dispatch_table(device)->WaitForPresentKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForPresentKHR);
    if (strcmp(pName, "vkGetBufferDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressKHR);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureAddressKHR);
    if (strcmp(pName, "vkGetDeviceMemoryOpaqueCaptureAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceMemoryOpaqueCaptureAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMemoryOpaqueCaptureAddressKHR);
    if (strcmp(pName, "vkCreateDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->CreateDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDeferredOperationKHR);
    if (strcmp(pName, "vkDestroyDeferredOperationKHR") == 0 && (!device || device_dispatch_table(device)->DestroyDeferredOperationKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDeferredOperationKHR);
    if (strcmp(pName, "vkGetDeferredOperationMaxConcurrencyKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationMaxConcurrencyKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationMaxConcurrencyKHR);
    if (strcmp(pName, "vkGetDeferredOperationResultKHR") == 0 && (!device || device_dispatch_table(device)->GetDeferredOperationResultKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeferredOperationResultKHR);
    if (strcmp(pName, "vkDeferredOperationJoinKHR") == 0 && (!device || device_dispatch_table(device)->DeferredOperationJoinKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDeferredOperationJoinKHR);
    if (strcmp(pName, "vkGetPipelineExecutablePropertiesKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutablePropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutablePropertiesKHR);
    if (strcmp(pName, "vkGetPipelineExecutableStatisticsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableStatisticsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableStatisticsKHR);
    if (strcmp(pName, "vkGetPipelineExecutableInternalRepresentationsKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineExecutableInternalRepresentationsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineExecutableInternalRepresentationsKHR);
    if (strcmp(pName, "vkMapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->MapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMapMemory2KHR);
    if (strcmp(pName, "vkUnmapMemory2KHR") == 0 && (!device || device_dispatch_table(device)->UnmapMemory2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnmapMemory2KHR);
    if (strcmp(pName, "vkGetEncodedVideoSessionParametersKHR") == 0 && (!device || device_dispatch_table(device)->GetEncodedVideoSessionParametersKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetEncodedVideoSessionParametersKHR);
    if (strcmp(pName, "vkCmdEncodeVideoKHR") == 0 && (!device || device_dispatch_table(device)->CmdEncodeVideoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEncodeVideoKHR);
    if (strcmp(pName, "vkCmdSetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdSetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetEvent2KHR);
    if (strcmp(pName, "vkCmdResetEvent2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResetEvent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResetEvent2KHR);
    if (strcmp(pName, "vkCmdWaitEvents2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWaitEvents2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWaitEvents2KHR);
    if (strcmp(pName, "vkCmdPipelineBarrier2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPipelineBarrier2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPipelineBarrier2KHR);
    if (strcmp(pName, "vkCmdWriteTimestamp2KHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteTimestamp2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteTimestamp2KHR);
    if (strcmp(pName, "vkQueueSubmit2KHR") == 0 && (!device || device_dispatch_table(device)->QueueSubmit2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSubmit2KHR);
    if (strcmp(pName, "vkCmdBindIndexBuffer3KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer3KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer3KHR);
    if (strcmp(pName, "vkCmdBindVertexBuffers3KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers3KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers3KHR);
    if (strcmp(pName, "vkCmdDrawIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirect2KHR);
    if (strcmp(pName, "vkCmdDrawIndexedIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirect2KHR);
    if (strcmp(pName, "vkCmdDispatchIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdDispatchIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchIndirect2KHR);
    if (strcmp(pName, "vkCmdCopyMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryKHR);
    if (strcmp(pName, "vkCmdCopyMemoryToImageKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageKHR);
    if (strcmp(pName, "vkCmdCopyImageToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToMemoryKHR);
    if (strcmp(pName, "vkCmdUpdateMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdUpdateMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdateMemoryKHR);
    if (strcmp(pName, "vkCmdFillMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdFillMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdFillMemoryKHR);
    if (strcmp(pName, "vkCmdCopyQueryPoolResultsToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyQueryPoolResultsToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyQueryPoolResultsToMemoryKHR);
    if (strcmp(pName, "vkCmdDrawIndirectCount2KHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCount2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCount2KHR);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCount2KHR") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCount2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCount2KHR);
    if (strcmp(pName, "vkCmdBeginConditionalRendering2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginConditionalRendering2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginConditionalRendering2EXT);
    if (strcmp(pName, "vkCmdBindTransformFeedbackBuffers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindTransformFeedbackBuffers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTransformFeedbackBuffers2EXT);
    if (strcmp(pName, "vkCmdBeginTransformFeedback2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginTransformFeedback2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginTransformFeedback2EXT);
    if (strcmp(pName, "vkCmdEndTransformFeedback2EXT") == 0 && (!device || device_dispatch_table(device)->CmdEndTransformFeedback2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndTransformFeedback2EXT);
    if (strcmp(pName, "vkCmdDrawIndirectByteCount2EXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectByteCount2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectByteCount2EXT);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirect2EXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirect2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirect2EXT);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectCount2EXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCount2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCount2EXT);
    if (strcmp(pName, "vkCmdWriteMarkerToMemoryAMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteMarkerToMemoryAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteMarkerToMemoryAMD);
    if (strcmp(pName, "vkCreateAccelerationStructure2KHR") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructure2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructure2KHR);
    if (strcmp(pName, "vkCmdCopyBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBuffer2KHR);
    if (strcmp(pName, "vkCmdCopyImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImage2KHR);
    if (strcmp(pName, "vkCmdCopyBufferToImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyBufferToImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyBufferToImage2KHR);
    if (strcmp(pName, "vkCmdCopyImageToBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyImageToBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyImageToBuffer2KHR);
    if (strcmp(pName, "vkCmdBlitImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBlitImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBlitImage2KHR);
    if (strcmp(pName, "vkCmdResolveImage2KHR") == 0 && (!device || device_dispatch_table(device)->CmdResolveImage2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdResolveImage2KHR);
    if (strcmp(pName, "vkCmdTraceRaysIndirect2KHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirect2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirect2KHR);
    if (strcmp(pName, "vkGetDeviceBufferMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceBufferMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceBufferMemoryRequirementsKHR);
    if (strcmp(pName, "vkGetDeviceImageMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageMemoryRequirementsKHR);
    if (strcmp(pName, "vkGetDeviceImageSparseMemoryRequirementsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSparseMemoryRequirementsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSparseMemoryRequirementsKHR);
    if (strcmp(pName, "vkCmdBindIndexBuffer2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindIndexBuffer2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindIndexBuffer2KHR);
    if (strcmp(pName, "vkGetRenderingAreaGranularityKHR") == 0 && (!device || device_dispatch_table(device)->GetRenderingAreaGranularityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRenderingAreaGranularityKHR);
    if (strcmp(pName, "vkGetDeviceImageSubresourceLayoutKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceImageSubresourceLayoutKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceImageSubresourceLayoutKHR);
    if (strcmp(pName, "vkGetImageSubresourceLayout2KHR") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2KHR);
    if (strcmp(pName, "vkWaitForPresent2KHR") == 0 && (!device || device_dispatch_table(device)->WaitForPresent2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWaitForPresent2KHR);
    if (strcmp(pName, "vkCreatePipelineBinariesKHR") == 0 && (!device || device_dispatch_table(device)->CreatePipelineBinariesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePipelineBinariesKHR);
    if (strcmp(pName, "vkDestroyPipelineBinaryKHR") == 0 && (!device || device_dispatch_table(device)->DestroyPipelineBinaryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPipelineBinaryKHR);
    if (strcmp(pName, "vkGetPipelineKeyKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineKeyKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineKeyKHR);
    if (strcmp(pName, "vkGetPipelineBinaryDataKHR") == 0 && (!device || device_dispatch_table(device)->GetPipelineBinaryDataKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineBinaryDataKHR);
    if (strcmp(pName, "vkReleaseCapturedPipelineDataKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseCapturedPipelineDataKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseCapturedPipelineDataKHR);
    if (strcmp(pName, "vkReleaseSwapchainImagesKHR") == 0 && (!device || device_dispatch_table(device)->ReleaseSwapchainImagesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseSwapchainImagesKHR);
    if (strcmp(pName, "vkCmdSetLineStippleKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleKHR);
    if (strcmp(pName, "vkGetCalibratedTimestampsKHR") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsKHR);
    if (strcmp(pName, "vkCmdBindDescriptorSets2KHR") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorSets2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorSets2KHR);
    if (strcmp(pName, "vkCmdPushConstants2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushConstants2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushConstants2KHR);
    if (strcmp(pName, "vkCmdPushDescriptorSet2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSet2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSet2KHR);
    if (strcmp(pName, "vkCmdPushDescriptorSetWithTemplate2KHR") == 0 && (!device || device_dispatch_table(device)->CmdPushDescriptorSetWithTemplate2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDescriptorSetWithTemplate2KHR);
    if (strcmp(pName, "vkCmdSetDescriptorBufferOffsets2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsets2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsets2EXT);
    if (strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplers2EXT);
    if (strcmp(pName, "vkCmdCopyMemoryIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryIndirectKHR);
    if (strcmp(pName, "vkCmdCopyMemoryToImageIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageIndirectKHR);
    if (strcmp(pName, "vkGetDeviceFaultReportsKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceFaultReportsKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceFaultReportsKHR);
    if (strcmp(pName, "vkGetDeviceFaultDebugInfoKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceFaultDebugInfoKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceFaultDebugInfoKHR);
    if (strcmp(pName, "vkCmdEndRendering2KHR") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering2KHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering2KHR);
    if (strcmp(pName, "vkDebugMarkerSetObjectTagEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectTagEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectTagEXT);
    if (strcmp(pName, "vkDebugMarkerSetObjectNameEXT") == 0 && (!device || device_dispatch_table(device)->DebugMarkerSetObjectNameEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDebugMarkerSetObjectNameEXT);
    if (strcmp(pName, "vkCmdDebugMarkerBeginEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerBeginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerBeginEXT);
    if (strcmp(pName, "vkCmdDebugMarkerEndEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerEndEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerEndEXT);
    if (strcmp(pName, "vkCmdDebugMarkerInsertEXT") == 0 && (!device || device_dispatch_table(device)->CmdDebugMarkerInsertEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDebugMarkerInsertEXT);
    if (strcmp(pName, "vkCmdBindTransformFeedbackBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindTransformFeedbackBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTransformFeedbackBuffersEXT);
    if (strcmp(pName, "vkCmdBeginTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginTransformFeedbackEXT);
    if (strcmp(pName, "vkCmdEndTransformFeedbackEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndTransformFeedbackEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndTransformFeedbackEXT);
    if (strcmp(pName, "vkCmdBeginQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginQueryIndexedEXT);
    if (strcmp(pName, "vkCmdEndQueryIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndQueryIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndQueryIndexedEXT);
    if (strcmp(pName, "vkCmdDrawIndirectByteCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectByteCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectByteCountEXT);
    if (strcmp(pName, "vkCreateCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuModuleNVX);
    if (strcmp(pName, "vkCreateCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->CreateCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCuFunctionNVX);
    if (strcmp(pName, "vkDestroyCuModuleNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuModuleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuModuleNVX);
    if (strcmp(pName, "vkDestroyCuFunctionNVX") == 0 && (!device || device_dispatch_table(device)->DestroyCuFunctionNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCuFunctionNVX);
    if (strcmp(pName, "vkCmdCuLaunchKernelNVX") == 0 && (!device || device_dispatch_table(device)->CmdCuLaunchKernelNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCuLaunchKernelNVX);
    if (strcmp(pName, "vkGetImageViewHandleNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewHandleNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewHandleNVX);
    if (strcmp(pName, "vkGetImageViewHandle64NVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewHandle64NVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewHandle64NVX);
    if (strcmp(pName, "vkGetImageViewAddressNVX") == 0 && (!device || device_dispatch_table(device)->GetImageViewAddressNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewAddressNVX);
    if (strcmp(pName, "vkGetDeviceCombinedImageSamplerIndexNVX") == 0 && (!device || device_dispatch_table(device)->GetDeviceCombinedImageSamplerIndexNVX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceCombinedImageSamplerIndexNVX);
    if (strcmp(pName, "vkCmdDrawIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndirectCountAMD);
    if (strcmp(pName, "vkCmdDrawIndexedIndirectCountAMD") == 0 && (!device || device_dispatch_table(device)->CmdDrawIndexedIndirectCountAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawIndexedIndirectCountAMD);
    if (strcmp(pName, "vkGetShaderInfoAMD") == 0 && (!device || device_dispatch_table(device)->GetShaderInfoAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderInfoAMD);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkGetMemoryWin32HandleNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryWin32HandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryWin32HandleNV);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCmdBeginConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginConditionalRenderingEXT);
    if (strcmp(pName, "vkCmdEndConditionalRenderingEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndConditionalRenderingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndConditionalRenderingEXT);
    if (strcmp(pName, "vkCmdSetViewportWScalingNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingNV);
    if (strcmp(pName, "vkDisplayPowerControlEXT") == 0 && (!device || device_dispatch_table(device)->DisplayPowerControlEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDisplayPowerControlEXT);
    if (strcmp(pName, "vkRegisterDeviceEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDeviceEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDeviceEventEXT);
    if (strcmp(pName, "vkRegisterDisplayEventEXT") == 0 && (!device || device_dispatch_table(device)->RegisterDisplayEventEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterDisplayEventEXT);
    if (strcmp(pName, "vkGetSwapchainCounterEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainCounterEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainCounterEXT);
    if (strcmp(pName, "vkGetRefreshCycleDurationGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetRefreshCycleDurationGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRefreshCycleDurationGOOGLE);
    if (strcmp(pName, "vkGetPastPresentationTimingGOOGLE") == 0 && (!device || device_dispatch_table(device)->GetPastPresentationTimingGOOGLE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPastPresentationTimingGOOGLE);
    if (strcmp(pName, "vkCmdSetDiscardRectangleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEXT);
    if (strcmp(pName, "vkCmdSetDiscardRectangleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleEnableEXT);
    if (strcmp(pName, "vkCmdSetDiscardRectangleModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDiscardRectangleModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDiscardRectangleModeEXT);
    if (strcmp(pName, "vkSetHdrMetadataEXT") == 0 && (!device || device_dispatch_table(device)->SetHdrMetadataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetHdrMetadataEXT);
    if (strcmp(pName, "vkSetDebugUtilsObjectNameEXT") == 0 && (!device || device_dispatch_table(device)->SetDebugUtilsObjectNameEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectNameEXT);
    if (strcmp(pName, "vkSetDebugUtilsObjectTagEXT") == 0 && (!device || device_dispatch_table(device)->SetDebugUtilsObjectTagEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDebugUtilsObjectTagEXT);
    if (strcmp(pName, "vkQueueBeginDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueBeginDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueBeginDebugUtilsLabelEXT);
    if (strcmp(pName, "vkQueueEndDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueEndDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueEndDebugUtilsLabelEXT);
    if (strcmp(pName, "vkQueueInsertDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->QueueInsertDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueInsertDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdBeginDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdEndDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdEndDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndDebugUtilsLabelEXT);
    if (strcmp(pName, "vkCmdInsertDebugUtilsLabelEXT") == 0 && (!device || device_dispatch_table(device)->CmdInsertDebugUtilsLabelEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInsertDebugUtilsLabelEXT);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    if (strcmp(pName, "vkGetAndroidHardwareBufferPropertiesANDROID") == 0 && (!device || device_dispatch_table(device)->GetAndroidHardwareBufferPropertiesANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAndroidHardwareBufferPropertiesANDROID);
    if (strcmp(pName, "vkGetMemoryAndroidHardwareBufferANDROID") == 0 && (!device || device_dispatch_table(device)->GetMemoryAndroidHardwareBufferANDROID))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryAndroidHardwareBufferANDROID);
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if (strcmp(pName, "vkCreateExecutionGraphPipelinesAMDX") == 0 && (!device || device_dispatch_table(device)->CreateExecutionGraphPipelinesAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateExecutionGraphPipelinesAMDX);
    if (strcmp(pName, "vkGetExecutionGraphPipelineScratchSizeAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineScratchSizeAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineScratchSizeAMDX);
    if (strcmp(pName, "vkGetExecutionGraphPipelineNodeIndexAMDX") == 0 && (!device || device_dispatch_table(device)->GetExecutionGraphPipelineNodeIndexAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExecutionGraphPipelineNodeIndexAMDX);
    if (strcmp(pName, "vkCmdInitializeGraphScratchMemoryAMDX") == 0 && (!device || device_dispatch_table(device)->CmdInitializeGraphScratchMemoryAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdInitializeGraphScratchMemoryAMDX);
    if (strcmp(pName, "vkCmdDispatchGraphAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphAMDX);
    if (strcmp(pName, "vkCmdDispatchGraphIndirectAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectAMDX);
    if (strcmp(pName, "vkCmdDispatchGraphIndirectCountAMDX") == 0 && (!device || device_dispatch_table(device)->CmdDispatchGraphIndirectCountAMDX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchGraphIndirectCountAMDX);
#endif  // VK_ENABLE_BETA_EXTENSIONS
    if (strcmp(pName, "vkWriteSamplerDescriptorsEXT") == 0 && (!device || device_dispatch_table(device)->WriteSamplerDescriptorsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteSamplerDescriptorsEXT);
    if (strcmp(pName, "vkWriteResourceDescriptorsEXT") == 0 && (!device || device_dispatch_table(device)->WriteResourceDescriptorsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteResourceDescriptorsEXT);
    if (strcmp(pName, "vkCmdBindSamplerHeapEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindSamplerHeapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindSamplerHeapEXT);
    if (strcmp(pName, "vkCmdBindResourceHeapEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindResourceHeapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindResourceHeapEXT);
    if (strcmp(pName, "vkCmdPushDataEXT") == 0 && (!device || device_dispatch_table(device)->CmdPushDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPushDataEXT);
    if (strcmp(pName, "vkGetImageOpaqueCaptureDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageOpaqueCaptureDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageOpaqueCaptureDataEXT);
    if (strcmp(pName, "vkRegisterCustomBorderColorEXT") == 0 && (!device || device_dispatch_table(device)->RegisterCustomBorderColorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkRegisterCustomBorderColorEXT);
    if (strcmp(pName, "vkUnregisterCustomBorderColorEXT") == 0 && (!device || device_dispatch_table(device)->UnregisterCustomBorderColorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUnregisterCustomBorderColorEXT);
    if (strcmp(pName, "vkGetTensorOpaqueCaptureDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorOpaqueCaptureDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorOpaqueCaptureDataARM);
    if (strcmp(pName, "vkCmdSetSampleLocationsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEXT);
    if (strcmp(pName, "vkGetImageDrmFormatModifierPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetImageDrmFormatModifierPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageDrmFormatModifierPropertiesEXT);
    if (strcmp(pName, "vkCreateValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->CreateValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateValidationCacheEXT);
    if (strcmp(pName, "vkDestroyValidationCacheEXT") == 0 && (!device || device_dispatch_table(device)->DestroyValidationCacheEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyValidationCacheEXT);
    if (strcmp(pName, "vkMergeValidationCachesEXT") == 0 && (!device || device_dispatch_table(device)->MergeValidationCachesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkMergeValidationCachesEXT);
    if (strcmp(pName, "vkGetValidationCacheDataEXT") == 0 && (!device || device_dispatch_table(device)->GetValidationCacheDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetValidationCacheDataEXT);
    if (strcmp(pName, "vkCmdBindShadingRateImageNV") == 0 && (!device || device_dispatch_table(device)->CmdBindShadingRateImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadingRateImageNV);
    if (strcmp(pName, "vkCmdSetViewportShadingRatePaletteNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportShadingRatePaletteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportShadingRatePaletteNV);
    if (strcmp(pName, "vkCmdSetCoarseSampleOrderNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoarseSampleOrderNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoarseSampleOrderNV);
    if (strcmp(pName, "vkCreateAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureNV);
    if (strcmp(pName, "vkDestroyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureNV);
    if (strcmp(pName, "vkGetAccelerationStructureMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureMemoryRequirementsNV);
    if (strcmp(pName, "vkBindAccelerationStructureMemoryNV") == 0 && (!device || device_dispatch_table(device)->BindAccelerationStructureMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindAccelerationStructureMemoryNV);
    if (strcmp(pName, "vkCmdBuildAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructureNV);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureNV);
    if (strcmp(pName, "vkCmdTraceRaysNV") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysNV);
    if (strcmp(pName, "vkCreateRayTracingPipelinesNV") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesNV);
    if (strcmp(pName, "vkGetRayTracingShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesKHR);
    if (strcmp(pName, "vkGetRayTracingShaderGroupHandlesNV") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupHandlesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupHandlesNV);
    if (strcmp(pName, "vkGetAccelerationStructureHandleNV") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureHandleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureHandleNV);
    if (strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesNV") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesNV);
    if (strcmp(pName, "vkCompileDeferredNV") == 0 && (!device || device_dispatch_table(device)->CompileDeferredNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCompileDeferredNV);
    if (strcmp(pName, "vkGetMemoryHostPointerPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryHostPointerPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryHostPointerPropertiesEXT);
    if (strcmp(pName, "vkCmdWriteBufferMarkerAMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarkerAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarkerAMD);
    if (strcmp(pName, "vkCmdWriteBufferMarker2AMD") == 0 && (!device || device_dispatch_table(device)->CmdWriteBufferMarker2AMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteBufferMarker2AMD);
    if (strcmp(pName, "vkGetCalibratedTimestampsEXT") == 0 && (!device || device_dispatch_table(device)->GetCalibratedTimestampsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCalibratedTimestampsEXT);
    if (strcmp(pName, "vkCmdDrawMeshTasksNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksNV);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectNV);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountNV);
    if (strcmp(pName, "vkCmdSetExclusiveScissorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorEnableNV);
    if (strcmp(pName, "vkCmdSetExclusiveScissorNV") == 0 && (!device || device_dispatch_table(device)->CmdSetExclusiveScissorNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExclusiveScissorNV);
    if (strcmp(pName, "vkCmdSetCheckpointNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCheckpointNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCheckpointNV);
    if (strcmp(pName, "vkGetQueueCheckpointDataNV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointDataNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointDataNV);
    if (strcmp(pName, "vkGetQueueCheckpointData2NV") == 0 && (!device || device_dispatch_table(device)->GetQueueCheckpointData2NV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetQueueCheckpointData2NV);
    if (strcmp(pName, "vkSetSwapchainPresentTimingQueueSizeEXT") == 0 && (!device || device_dispatch_table(device)->SetSwapchainPresentTimingQueueSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetSwapchainPresentTimingQueueSizeEXT);
    if (strcmp(pName, "vkGetSwapchainTimingPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainTimingPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainTimingPropertiesEXT);
    if (strcmp(pName, "vkGetSwapchainTimeDomainPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetSwapchainTimeDomainPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSwapchainTimeDomainPropertiesEXT);
    if (strcmp(pName, "vkGetPastPresentationTimingEXT") == 0 && (!device || device_dispatch_table(device)->GetPastPresentationTimingEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPastPresentationTimingEXT);
    if (strcmp(pName, "vkInitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->InitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkInitializePerformanceApiINTEL);
    if (strcmp(pName, "vkUninitializePerformanceApiINTEL") == 0 && (!device || device_dispatch_table(device)->UninitializePerformanceApiINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUninitializePerformanceApiINTEL);
    if (strcmp(pName, "vkCmdSetPerformanceMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceMarkerINTEL);
    if (strcmp(pName, "vkCmdSetPerformanceStreamMarkerINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceStreamMarkerINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceStreamMarkerINTEL);
    if (strcmp(pName, "vkCmdSetPerformanceOverrideINTEL") == 0 && (!device || device_dispatch_table(device)->CmdSetPerformanceOverrideINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPerformanceOverrideINTEL);
    if (strcmp(pName, "vkAcquirePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->AcquirePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquirePerformanceConfigurationINTEL);
    if (strcmp(pName, "vkReleasePerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->ReleasePerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleasePerformanceConfigurationINTEL);
    if (strcmp(pName, "vkQueueSetPerformanceConfigurationINTEL") == 0 && (!device || device_dispatch_table(device)->QueueSetPerformanceConfigurationINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSetPerformanceConfigurationINTEL);
    if (strcmp(pName, "vkGetPerformanceParameterINTEL") == 0 && (!device || device_dispatch_table(device)->GetPerformanceParameterINTEL))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPerformanceParameterINTEL);
    if (strcmp(pName, "vkSetLocalDimmingAMD") == 0 && (!device || device_dispatch_table(device)->SetLocalDimmingAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLocalDimmingAMD);
    if (strcmp(pName, "vkGetBufferDeviceAddressEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferDeviceAddressEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferDeviceAddressEXT);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    if (strcmp(pName, "vkAcquireFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->AcquireFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAcquireFullScreenExclusiveModeEXT);
    if (strcmp(pName, "vkReleaseFullScreenExclusiveModeEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseFullScreenExclusiveModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseFullScreenExclusiveModeEXT);
    if (strcmp(pName, "vkGetDeviceGroupSurfacePresentModes2EXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceGroupSurfacePresentModes2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceGroupSurfacePresentModes2EXT);
#endif  // VK_USE_PLATFORM_WIN32_KHR
    if (strcmp(pName, "vkCmdSetLineStippleEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEXT);
    if (strcmp(pName, "vkResetQueryPoolEXT") == 0 && (!device || device_dispatch_table(device)->ResetQueryPoolEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkResetQueryPoolEXT);
    if (strcmp(pName, "vkCmdSetCullModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetCullModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCullModeEXT);
    if (strcmp(pName, "vkCmdSetFrontFaceEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetFrontFaceEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFrontFaceEXT);
    if (strcmp(pName, "vkCmdSetPrimitiveTopologyEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveTopologyEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveTopologyEXT);
    if (strcmp(pName, "vkCmdSetViewportWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWithCountEXT);
    if (strcmp(pName, "vkCmdSetScissorWithCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetScissorWithCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetScissorWithCountEXT);
    if (strcmp(pName, "vkCmdBindVertexBuffers2EXT") == 0 && (!device || device_dispatch_table(device)->CmdBindVertexBuffers2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindVertexBuffers2EXT);
    if (strcmp(pName, "vkCmdSetDepthTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthTestEnableEXT);
    if (strcmp(pName, "vkCmdSetDepthWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthWriteEnableEXT);
    if (strcmp(pName, "vkCmdSetDepthCompareOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthCompareOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthCompareOpEXT);
    if (strcmp(pName, "vkCmdSetDepthBoundsTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBoundsTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBoundsTestEnableEXT);
    if (strcmp(pName, "vkCmdSetStencilTestEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilTestEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilTestEnableEXT);
    if (strcmp(pName, "vkCmdSetStencilOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetStencilOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetStencilOpEXT);
    if (strcmp(pName, "vkCopyMemoryToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToImageEXT);
    if (strcmp(pName, "vkCopyImageToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToMemoryEXT);
    if (strcmp(pName, "vkCopyImageToImageEXT") == 0 && (!device || device_dispatch_table(device)->CopyImageToImageEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyImageToImageEXT);
    if (strcmp(pName, "vkTransitionImageLayoutEXT") == 0 && (!device || device_dispatch_table(device)->TransitionImageLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkTransitionImageLayoutEXT);
    if (strcmp(pName, "vkGetImageSubresourceLayout2EXT") == 0 && (!device || device_dispatch_table(device)->GetImageSubresourceLayout2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageSubresourceLayout2EXT);
    if (strcmp(pName, "vkReleaseSwapchainImagesEXT") == 0 && (!device || device_dispatch_table(device)->ReleaseSwapchainImagesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkReleaseSwapchainImagesEXT);
    if (strcmp(pName, "vkGetGeneratedCommandsMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetGeneratedCommandsMemoryRequirementsNV);
    if (strcmp(pName, "vkCmdPreprocessGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdPreprocessGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPreprocessGeneratedCommandsNV);
    if (strcmp(pName, "vkCmdExecuteGeneratedCommandsNV") == 0 && (!device || device_dispatch_table(device)->CmdExecuteGeneratedCommandsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteGeneratedCommandsNV);
    if (strcmp(pName, "vkCmdBindPipelineShaderGroupNV") == 0 && (!device || device_dispatch_table(device)->CmdBindPipelineShaderGroupNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindPipelineShaderGroupNV);
    if (strcmp(pName, "vkCreateIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->CreateIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectCommandsLayoutNV);
    if (strcmp(pName, "vkDestroyIndirectCommandsLayoutNV") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectCommandsLayoutNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectCommandsLayoutNV);
    if (strcmp(pName, "vkCmdSetDepthBias2EXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBias2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBias2EXT);
    if (strcmp(pName, "vkCreatePrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->CreatePrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreatePrivateDataSlotEXT);
    if (strcmp(pName, "vkDestroyPrivateDataSlotEXT") == 0 && (!device || device_dispatch_table(device)->DestroyPrivateDataSlotEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyPrivateDataSlotEXT);
    if (strcmp(pName, "vkSetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->SetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetPrivateDataEXT);
    if (strcmp(pName, "vkGetPrivateDataEXT") == 0 && (!device || device_dispatch_table(device)->GetPrivateDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPrivateDataEXT);
    if (strcmp(pName, "vkQueueSetPerfHintQCOM") == 0 && (!device || device_dispatch_table(device)->QueueSetPerfHintQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueSetPerfHintQCOM);
#if defined(VK_ENABLE_BETA_EXTENSIONS)
    if (strcmp(pName, "vkCreateCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaModuleNV);
    if (strcmp(pName, "vkGetCudaModuleCacheNV") == 0 && (!device || device_dispatch_table(device)->GetCudaModuleCacheNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetCudaModuleCacheNV);
    if (strcmp(pName, "vkCreateCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->CreateCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateCudaFunctionNV);
    if (strcmp(pName, "vkDestroyCudaModuleNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaModuleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaModuleNV);
    if (strcmp(pName, "vkDestroyCudaFunctionNV") == 0 && (!device || device_dispatch_table(device)->DestroyCudaFunctionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyCudaFunctionNV);
    if (strcmp(pName, "vkCmdCudaLaunchKernelNV") == 0 && (!device || device_dispatch_table(device)->CmdCudaLaunchKernelNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCudaLaunchKernelNV);
#endif  // VK_ENABLE_BETA_EXTENSIONS
    if (strcmp(pName, "vkCmdDispatchTileQCOM") == 0 && (!device || device_dispatch_table(device)->CmdDispatchTileQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchTileQCOM);
    if (strcmp(pName, "vkCmdBeginPerTileExecutionQCOM") == 0 && (!device || device_dispatch_table(device)->CmdBeginPerTileExecutionQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginPerTileExecutionQCOM);
    if (strcmp(pName, "vkCmdEndPerTileExecutionQCOM") == 0 && (!device || device_dispatch_table(device)->CmdEndPerTileExecutionQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndPerTileExecutionQCOM);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkExportMetalObjectsEXT") == 0 && (!device || device_dispatch_table(device)->ExportMetalObjectsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkExportMetalObjectsEXT);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkGetDescriptorSetLayoutSizeEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutSizeEXT);
    if (strcmp(pName, "vkGetDescriptorSetLayoutBindingOffsetEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutBindingOffsetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutBindingOffsetEXT);
    if (strcmp(pName, "vkGetDescriptorEXT") == 0 && (!device || device_dispatch_table(device)->GetDescriptorEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorEXT);
    if (strcmp(pName, "vkCmdBindDescriptorBuffersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBuffersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBuffersEXT);
    if (strcmp(pName, "vkCmdSetDescriptorBufferOffsetsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDescriptorBufferOffsetsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDescriptorBufferOffsetsEXT);
    if (strcmp(pName, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindDescriptorBufferEmbeddedSamplersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindDescriptorBufferEmbeddedSamplersEXT);
    if (strcmp(pName, "vkGetBufferOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetBufferOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferOpaqueCaptureDescriptorDataEXT);
    if (strcmp(pName, "vkGetImageOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageOpaqueCaptureDescriptorDataEXT);
    if (strcmp(pName, "vkGetImageViewOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetImageViewOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetImageViewOpaqueCaptureDescriptorDataEXT);
    if (strcmp(pName, "vkGetSamplerOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetSamplerOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSamplerOpaqueCaptureDescriptorDataEXT);
    if (strcmp(pName, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT);
    if (strcmp(pName, "vkCmdSetFragmentShadingRateEnumNV") == 0 && (!device || device_dispatch_table(device)->CmdSetFragmentShadingRateEnumNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetFragmentShadingRateEnumNV);
    if (strcmp(pName, "vkGetDeviceFaultInfoEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceFaultInfoEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceFaultInfoEXT);
    if (strcmp(pName, "vkCmdSetVertexInputEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetVertexInputEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetVertexInputEXT);
#if defined(VK_USE_PLATFORM_FUCHSIA)
    if (strcmp(pName, "vkGetMemoryZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandleFUCHSIA);
    if (strcmp(pName, "vkGetMemoryZirconHandlePropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetMemoryZirconHandlePropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryZirconHandlePropertiesFUCHSIA);
    if (strcmp(pName, "vkImportSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->ImportSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkImportSemaphoreZirconHandleFUCHSIA);
    if (strcmp(pName, "vkGetSemaphoreZirconHandleFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetSemaphoreZirconHandleFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetSemaphoreZirconHandleFUCHSIA);
    if (strcmp(pName, "vkCreateBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->CreateBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateBufferCollectionFUCHSIA);
    if (strcmp(pName, "vkSetBufferCollectionImageConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionImageConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionImageConstraintsFUCHSIA);
    if (strcmp(pName, "vkSetBufferCollectionBufferConstraintsFUCHSIA") == 0 && (!device || device_dispatch_table(device)->SetBufferCollectionBufferConstraintsFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetBufferCollectionBufferConstraintsFUCHSIA);
    if (strcmp(pName, "vkDestroyBufferCollectionFUCHSIA") == 0 && (!device || device_dispatch_table(device)->DestroyBufferCollectionFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyBufferCollectionFUCHSIA);
    if (strcmp(pName, "vkGetBufferCollectionPropertiesFUCHSIA") == 0 && (!device || device_dispatch_table(device)->GetBufferCollectionPropertiesFUCHSIA))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetBufferCollectionPropertiesFUCHSIA);
#endif  // VK_USE_PLATFORM_FUCHSIA
    if (strcmp(pName, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI") == 0 && (!device || device_dispatch_table(device)->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI);
    if (strcmp(pName, "vkCmdSubpassShadingHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdSubpassShadingHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSubpassShadingHUAWEI);
    if (strcmp(pName, "vkCmdBindInvocationMaskHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdBindInvocationMaskHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindInvocationMaskHUAWEI);
    if (strcmp(pName, "vkGetMemoryRemoteAddressNV") == 0 && (!device || device_dispatch_table(device)->GetMemoryRemoteAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryRemoteAddressNV);
    if (strcmp(pName, "vkGetPipelinePropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetPipelinePropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelinePropertiesEXT);
    if (strcmp(pName, "vkCmdSetPatchControlPointsEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPatchControlPointsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPatchControlPointsEXT);
    if (strcmp(pName, "vkCmdSetRasterizerDiscardEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizerDiscardEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizerDiscardEnableEXT);
    if (strcmp(pName, "vkCmdSetDepthBiasEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthBiasEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthBiasEnableEXT);
    if (strcmp(pName, "vkCmdSetLogicOpEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEXT);
    if (strcmp(pName, "vkCmdSetPrimitiveRestartEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartEnableEXT);
    if (strcmp(pName, "vkCmdSetColorWriteEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteEnableEXT);
    if (strcmp(pName, "vkCmdDrawMultiEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiEXT);
    if (strcmp(pName, "vkCmdDrawMultiIndexedEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMultiIndexedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMultiIndexedEXT);
    if (strcmp(pName, "vkCreateMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CreateMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateMicromapEXT);
    if (strcmp(pName, "vkDestroyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->DestroyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyMicromapEXT);
    if (strcmp(pName, "vkCmdBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->CmdBuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildMicromapsEXT);
    if (strcmp(pName, "vkBuildMicromapsEXT") == 0 && (!device || device_dispatch_table(device)->BuildMicromapsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildMicromapsEXT);
    if (strcmp(pName, "vkCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapEXT);
    if (strcmp(pName, "vkCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMicromapToMemoryEXT);
    if (strcmp(pName, "vkCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToMicromapEXT);
    if (strcmp(pName, "vkWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->WriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteMicromapsPropertiesEXT);
    if (strcmp(pName, "vkCmdCopyMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapEXT);
    if (strcmp(pName, "vkCmdCopyMicromapToMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMicromapToMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMicromapToMemoryEXT);
    if (strcmp(pName, "vkCmdCopyMemoryToMicromapEXT") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToMicromapEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToMicromapEXT);
    if (strcmp(pName, "vkCmdWriteMicromapsPropertiesEXT") == 0 && (!device || device_dispatch_table(device)->CmdWriteMicromapsPropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteMicromapsPropertiesEXT);
    if (strcmp(pName, "vkGetDeviceMicromapCompatibilityEXT") == 0 && (!device || device_dispatch_table(device)->GetDeviceMicromapCompatibilityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceMicromapCompatibilityEXT);
    if (strcmp(pName, "vkGetMicromapBuildSizesEXT") == 0 && (!device || device_dispatch_table(device)->GetMicromapBuildSizesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMicromapBuildSizesEXT);
    if (strcmp(pName, "vkCmdDrawClusterHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterHUAWEI);
    if (strcmp(pName, "vkCmdDrawClusterIndirectHUAWEI") == 0 && (!device || device_dispatch_table(device)->CmdDrawClusterIndirectHUAWEI))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawClusterIndirectHUAWEI);
    if (strcmp(pName, "vkSetDeviceMemoryPriorityEXT") == 0 && (!device || device_dispatch_table(device)->SetDeviceMemoryPriorityEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetDeviceMemoryPriorityEXT);
    if (strcmp(pName, "vkCmdSetDispatchParametersARM") == 0 && (!device || device_dispatch_table(device)->CmdSetDispatchParametersARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDispatchParametersARM);
    if (strcmp(pName, "vkGetDescriptorSetLayoutHostMappingInfoVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetLayoutHostMappingInfoVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetLayoutHostMappingInfoVALVE);
    if (strcmp(pName, "vkGetDescriptorSetHostMappingVALVE") == 0 && (!device || device_dispatch_table(device)->GetDescriptorSetHostMappingVALVE))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDescriptorSetHostMappingVALVE);
    if (strcmp(pName, "vkCmdCopyMemoryIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryIndirectNV);
    if (strcmp(pName, "vkCmdCopyMemoryToImageIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToImageIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToImageIndirectNV);
    if (strcmp(pName, "vkCmdDecompressMemoryNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryNV);
    if (strcmp(pName, "vkCmdDecompressMemoryIndirectCountNV") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryIndirectCountNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryIndirectCountNV);
    if (strcmp(pName, "vkGetPipelineIndirectMemoryRequirementsNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectMemoryRequirementsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectMemoryRequirementsNV);
    if (strcmp(pName, "vkCmdUpdatePipelineIndirectBufferNV") == 0 && (!device || device_dispatch_table(device)->CmdUpdatePipelineIndirectBufferNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdUpdatePipelineIndirectBufferNV);
    if (strcmp(pName, "vkGetPipelineIndirectDeviceAddressNV") == 0 && (!device || device_dispatch_table(device)->GetPipelineIndirectDeviceAddressNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPipelineIndirectDeviceAddressNV);
#if defined(VK_USE_PLATFORM_OHOS)
    if (strcmp(pName, "vkGetNativeBufferPropertiesOHOS") == 0 && (!device || device_dispatch_table(device)->GetNativeBufferPropertiesOHOS))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetNativeBufferPropertiesOHOS);
    if (strcmp(pName, "vkGetMemoryNativeBufferOHOS") == 0 && (!device || device_dispatch_table(device)->GetMemoryNativeBufferOHOS))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryNativeBufferOHOS);
#endif  // VK_USE_PLATFORM_OHOS
    if (strcmp(pName, "vkCmdSetDepthClampEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClampEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClampEnableEXT);
    if (strcmp(pName, "vkCmdSetPolygonModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPolygonModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPolygonModeEXT);
    if (strcmp(pName, "vkCmdSetRasterizationSamplesEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationSamplesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationSamplesEXT);
    if (strcmp(pName, "vkCmdSetSampleMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleMaskEXT);
    if (strcmp(pName, "vkCmdSetAlphaToCoverageEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToCoverageEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToCoverageEnableEXT);
    if (strcmp(pName, "vkCmdSetAlphaToOneEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAlphaToOneEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAlphaToOneEnableEXT);
    if (strcmp(pName, "vkCmdSetLogicOpEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLogicOpEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLogicOpEnableEXT);
    if (strcmp(pName, "vkCmdSetColorBlendEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEnableEXT);
    if (strcmp(pName, "vkCmdSetColorBlendEquationEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendEquationEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendEquationEXT);
    if (strcmp(pName, "vkCmdSetColorWriteMaskEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorWriteMaskEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorWriteMaskEXT);
    if (strcmp(pName, "vkCmdSetTessellationDomainOriginEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetTessellationDomainOriginEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetTessellationDomainOriginEXT);
    if (strcmp(pName, "vkCmdSetRasterizationStreamEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetRasterizationStreamEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRasterizationStreamEXT);
    if (strcmp(pName, "vkCmdSetConservativeRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetConservativeRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetConservativeRasterizationModeEXT);
    if (strcmp(pName, "vkCmdSetExtraPrimitiveOverestimationSizeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetExtraPrimitiveOverestimationSizeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetExtraPrimitiveOverestimationSizeEXT);
    if (strcmp(pName, "vkCmdSetDepthClipEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipEnableEXT);
    if (strcmp(pName, "vkCmdSetSampleLocationsEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetSampleLocationsEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetSampleLocationsEnableEXT);
    if (strcmp(pName, "vkCmdSetColorBlendAdvancedEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetColorBlendAdvancedEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetColorBlendAdvancedEXT);
    if (strcmp(pName, "vkCmdSetProvokingVertexModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetProvokingVertexModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetProvokingVertexModeEXT);
    if (strcmp(pName, "vkCmdSetLineRasterizationModeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineRasterizationModeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineRasterizationModeEXT);
    if (strcmp(pName, "vkCmdSetLineStippleEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetLineStippleEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetLineStippleEnableEXT);
    if (strcmp(pName, "vkCmdSetDepthClipNegativeOneToOneEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClipNegativeOneToOneEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClipNegativeOneToOneEXT);
    if (strcmp(pName, "vkCmdSetViewportWScalingEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportWScalingEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportWScalingEnableNV);
    if (strcmp(pName, "vkCmdSetViewportSwizzleNV") == 0 && (!device || device_dispatch_table(device)->CmdSetViewportSwizzleNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetViewportSwizzleNV);
    if (strcmp(pName, "vkCmdSetCoverageToColorEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorEnableNV);
    if (strcmp(pName, "vkCmdSetCoverageToColorLocationNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageToColorLocationNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageToColorLocationNV);
    if (strcmp(pName, "vkCmdSetCoverageModulationModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationModeNV);
    if (strcmp(pName, "vkCmdSetCoverageModulationTableEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableEnableNV);
    if (strcmp(pName, "vkCmdSetCoverageModulationTableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageModulationTableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageModulationTableNV);
    if (strcmp(pName, "vkCmdSetShadingRateImageEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetShadingRateImageEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetShadingRateImageEnableNV);
    if (strcmp(pName, "vkCmdSetRepresentativeFragmentTestEnableNV") == 0 && (!device || device_dispatch_table(device)->CmdSetRepresentativeFragmentTestEnableNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRepresentativeFragmentTestEnableNV);
    if (strcmp(pName, "vkCmdSetCoverageReductionModeNV") == 0 && (!device || device_dispatch_table(device)->CmdSetCoverageReductionModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetCoverageReductionModeNV);
    if (strcmp(pName, "vkCreateTensorARM") == 0 && (!device || device_dispatch_table(device)->CreateTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateTensorARM);
    if (strcmp(pName, "vkDestroyTensorARM") == 0 && (!device || device_dispatch_table(device)->DestroyTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyTensorARM);
    if (strcmp(pName, "vkCreateTensorViewARM") == 0 && (!device || device_dispatch_table(device)->CreateTensorViewARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateTensorViewARM);
    if (strcmp(pName, "vkDestroyTensorViewARM") == 0 && (!device || device_dispatch_table(device)->DestroyTensorViewARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyTensorViewARM);
    if (strcmp(pName, "vkGetTensorMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetTensorMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorMemoryRequirementsARM);
    if (strcmp(pName, "vkBindTensorMemoryARM") == 0 && (!device || device_dispatch_table(device)->BindTensorMemoryARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindTensorMemoryARM);
    if (strcmp(pName, "vkGetDeviceTensorMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDeviceTensorMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceTensorMemoryRequirementsARM);
    if (strcmp(pName, "vkCmdCopyTensorARM") == 0 && (!device || device_dispatch_table(device)->CmdCopyTensorARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyTensorARM);
    if (strcmp(pName, "vkGetTensorOpaqueCaptureDescriptorDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorOpaqueCaptureDescriptorDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorOpaqueCaptureDescriptorDataARM);
    if (strcmp(pName, "vkGetTensorViewOpaqueCaptureDescriptorDataARM") == 0 && (!device || device_dispatch_table(device)->GetTensorViewOpaqueCaptureDescriptorDataARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetTensorViewOpaqueCaptureDescriptorDataARM);
    if (strcmp(pName, "vkGetShaderModuleIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleIdentifierEXT);
    if (strcmp(pName, "vkGetShaderModuleCreateInfoIdentifierEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderModuleCreateInfoIdentifierEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderModuleCreateInfoIdentifierEXT);
    if (strcmp(pName, "vkCreateOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->CreateOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateOpticalFlowSessionNV);
    if (strcmp(pName, "vkDestroyOpticalFlowSessionNV") == 0 && (!device || device_dispatch_table(device)->DestroyOpticalFlowSessionNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyOpticalFlowSessionNV);
    if (strcmp(pName, "vkBindOpticalFlowSessionImageNV") == 0 && (!device || device_dispatch_table(device)->BindOpticalFlowSessionImageNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindOpticalFlowSessionImageNV);
    if (strcmp(pName, "vkCmdOpticalFlowExecuteNV") == 0 && (!device || device_dispatch_table(device)->CmdOpticalFlowExecuteNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdOpticalFlowExecuteNV);
    if (strcmp(pName, "vkAntiLagUpdateAMD") == 0 && (!device || device_dispatch_table(device)->AntiLagUpdateAMD))
        return reinterpret_cast<PFN_vkVoidFunction>(vkAntiLagUpdateAMD);
    if (strcmp(pName, "vkCreateShadersEXT") == 0 && (!device || device_dispatch_table(device)->CreateShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShadersEXT);
    if (strcmp(pName, "vkDestroyShaderEXT") == 0 && (!device || device_dispatch_table(device)->DestroyShaderEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderEXT);
    if (strcmp(pName, "vkGetShaderBinaryDataEXT") == 0 && (!device || device_dispatch_table(device)->GetShaderBinaryDataEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderBinaryDataEXT);
    if (strcmp(pName, "vkCmdBindShadersEXT") == 0 && (!device || device_dispatch_table(device)->CmdBindShadersEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindShadersEXT);
    if (strcmp(pName, "vkCmdSetDepthClampRangeEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetDepthClampRangeEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetDepthClampRangeEXT);
    if (strcmp(pName, "vkGetFramebufferTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetFramebufferTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetFramebufferTilePropertiesQCOM);
    if (strcmp(pName, "vkGetDynamicRenderingTilePropertiesQCOM") == 0 && (!device || device_dispatch_table(device)->GetDynamicRenderingTilePropertiesQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDynamicRenderingTilePropertiesQCOM);
    if (strcmp(pName, "vkConvertCooperativeVectorMatrixNV") == 0 && (!device || device_dispatch_table(device)->ConvertCooperativeVectorMatrixNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkConvertCooperativeVectorMatrixNV);
    if (strcmp(pName, "vkCmdConvertCooperativeVectorMatrixNV") == 0 && (!device || device_dispatch_table(device)->CmdConvertCooperativeVectorMatrixNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdConvertCooperativeVectorMatrixNV);
    if (strcmp(pName, "vkSetLatencySleepModeNV") == 0 && (!device || device_dispatch_table(device)->SetLatencySleepModeNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencySleepModeNV);
    if (strcmp(pName, "vkLatencySleepNV") == 0 && (!device || device_dispatch_table(device)->LatencySleepNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkLatencySleepNV);
    if (strcmp(pName, "vkSetLatencyMarkerNV") == 0 && (!device || device_dispatch_table(device)->SetLatencyMarkerNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkSetLatencyMarkerNV);
    if (strcmp(pName, "vkGetLatencyTimingsNV") == 0 && (!device || device_dispatch_table(device)->GetLatencyTimingsNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetLatencyTimingsNV);
    if (strcmp(pName, "vkQueueNotifyOutOfBandNV") == 0 && (!device || device_dispatch_table(device)->QueueNotifyOutOfBandNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkQueueNotifyOutOfBandNV);
    if (strcmp(pName, "vkCreateDataGraphPipelinesARM") == 0 && (!device || device_dispatch_table(device)->CreateDataGraphPipelinesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDataGraphPipelinesARM);
    if (strcmp(pName, "vkCreateDataGraphPipelineSessionARM") == 0 && (!device || device_dispatch_table(device)->CreateDataGraphPipelineSessionARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateDataGraphPipelineSessionARM);
    if (strcmp(pName, "vkGetDataGraphPipelineSessionBindPointRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineSessionBindPointRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineSessionBindPointRequirementsARM);
    if (strcmp(pName, "vkGetDataGraphPipelineSessionMemoryRequirementsARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineSessionMemoryRequirementsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineSessionMemoryRequirementsARM);
    if (strcmp(pName, "vkBindDataGraphPipelineSessionMemoryARM") == 0 && (!device || device_dispatch_table(device)->BindDataGraphPipelineSessionMemoryARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBindDataGraphPipelineSessionMemoryARM);
    if (strcmp(pName, "vkDestroyDataGraphPipelineSessionARM") == 0 && (!device || device_dispatch_table(device)->DestroyDataGraphPipelineSessionARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyDataGraphPipelineSessionARM);
    if (strcmp(pName, "vkCmdDispatchDataGraphARM") == 0 && (!device || device_dispatch_table(device)->CmdDispatchDataGraphARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDispatchDataGraphARM);
    if (strcmp(pName, "vkGetDataGraphPipelineAvailablePropertiesARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelineAvailablePropertiesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelineAvailablePropertiesARM);
    if (strcmp(pName, "vkGetDataGraphPipelinePropertiesARM") == 0 && (!device || device_dispatch_table(device)->GetDataGraphPipelinePropertiesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDataGraphPipelinePropertiesARM);
    if (strcmp(pName, "vkCmdSetAttachmentFeedbackLoopEnableEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetAttachmentFeedbackLoopEnableEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetAttachmentFeedbackLoopEnableEXT);
#if defined(VK_USE_PLATFORM_SCREEN_QNX)
    if (strcmp(pName, "vkGetScreenBufferPropertiesQNX") == 0 && (!device || device_dispatch_table(device)->GetScreenBufferPropertiesQNX))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetScreenBufferPropertiesQNX);
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    if (strcmp(pName, "vkCmdBindTileMemoryQCOM") == 0 && (!device || device_dispatch_table(device)->CmdBindTileMemoryQCOM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBindTileMemoryQCOM);
    if (strcmp(pName, "vkCmdDecompressMemoryEXT") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryEXT);
    if (strcmp(pName, "vkCmdDecompressMemoryIndirectCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDecompressMemoryIndirectCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDecompressMemoryIndirectCountEXT);
    if (strcmp(pName, "vkCreateExternalComputeQueueNV") == 0 && (!device || device_dispatch_table(device)->CreateExternalComputeQueueNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateExternalComputeQueueNV);
    if (strcmp(pName, "vkDestroyExternalComputeQueueNV") == 0 && (!device || device_dispatch_table(device)->DestroyExternalComputeQueueNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyExternalComputeQueueNV);
    if (strcmp(pName, "vkGetExternalComputeQueueDataNV") == 0 && (!device || device_dispatch_table(device)->GetExternalComputeQueueDataNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetExternalComputeQueueDataNV);
    if (strcmp(pName, "vkGetClusterAccelerationStructureBuildSizesNV") == 0 && (!device || device_dispatch_table(device)->GetClusterAccelerationStructureBuildSizesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetClusterAccelerationStructureBuildSizesNV);
    if (strcmp(pName, "vkCmdBuildClusterAccelerationStructureIndirectNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildClusterAccelerationStructureIndirectNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildClusterAccelerationStructureIndirectNV);
    if (strcmp(pName, "vkGetPartitionedAccelerationStructuresBuildSizesNV") == 0 && (!device || device_dispatch_table(device)->GetPartitionedAccelerationStructuresBuildSizesNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetPartitionedAccelerationStructuresBuildSizesNV);
    if (strcmp(pName, "vkCmdBuildPartitionedAccelerationStructuresNV") == 0 && (!device || device_dispatch_table(device)->CmdBuildPartitionedAccelerationStructuresNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildPartitionedAccelerationStructuresNV);
    if (strcmp(pName, "vkGetGeneratedCommandsMemoryRequirementsEXT") == 0 && (!device || device_dispatch_table(device)->GetGeneratedCommandsMemoryRequirementsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetGeneratedCommandsMemoryRequirementsEXT);
    if (strcmp(pName, "vkCmdPreprocessGeneratedCommandsEXT") == 0 && (!device || device_dispatch_table(device)->CmdPreprocessGeneratedCommandsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdPreprocessGeneratedCommandsEXT);
    if (strcmp(pName, "vkCmdExecuteGeneratedCommandsEXT") == 0 && (!device || device_dispatch_table(device)->CmdExecuteGeneratedCommandsEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdExecuteGeneratedCommandsEXT);
    if (strcmp(pName, "vkCreateIndirectCommandsLayoutEXT") == 0 && (!device || device_dispatch_table(device)->CreateIndirectCommandsLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectCommandsLayoutEXT);
    if (strcmp(pName, "vkDestroyIndirectCommandsLayoutEXT") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectCommandsLayoutEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectCommandsLayoutEXT);
    if (strcmp(pName, "vkCreateIndirectExecutionSetEXT") == 0 && (!device || device_dispatch_table(device)->CreateIndirectExecutionSetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateIndirectExecutionSetEXT);
    if (strcmp(pName, "vkDestroyIndirectExecutionSetEXT") == 0 && (!device || device_dispatch_table(device)->DestroyIndirectExecutionSetEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyIndirectExecutionSetEXT);
    if (strcmp(pName, "vkUpdateIndirectExecutionSetPipelineEXT") == 0 && (!device || device_dispatch_table(device)->UpdateIndirectExecutionSetPipelineEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateIndirectExecutionSetPipelineEXT);
    if (strcmp(pName, "vkUpdateIndirectExecutionSetShaderEXT") == 0 && (!device || device_dispatch_table(device)->UpdateIndirectExecutionSetShaderEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkUpdateIndirectExecutionSetShaderEXT);
#if defined(VK_USE_PLATFORM_METAL_EXT)
    if (strcmp(pName, "vkGetMemoryMetalHandleEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryMetalHandleEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryMetalHandleEXT);
    if (strcmp(pName, "vkGetMemoryMetalHandlePropertiesEXT") == 0 && (!device || device_dispatch_table(device)->GetMemoryMetalHandlePropertiesEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetMemoryMetalHandlePropertiesEXT);
#endif  // VK_USE_PLATFORM_METAL_EXT
    if (strcmp(pName, "vkCreateShaderInstrumentationARM") == 0 && (!device || device_dispatch_table(device)->CreateShaderInstrumentationARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateShaderInstrumentationARM);
    if (strcmp(pName, "vkDestroyShaderInstrumentationARM") == 0 && (!device || device_dispatch_table(device)->DestroyShaderInstrumentationARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyShaderInstrumentationARM);
    if (strcmp(pName, "vkCmdBeginShaderInstrumentationARM") == 0 && (!device || device_dispatch_table(device)->CmdBeginShaderInstrumentationARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginShaderInstrumentationARM);
    if (strcmp(pName, "vkCmdEndShaderInstrumentationARM") == 0 && (!device || device_dispatch_table(device)->CmdEndShaderInstrumentationARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndShaderInstrumentationARM);
    if (strcmp(pName, "vkGetShaderInstrumentationValuesARM") == 0 && (!device || device_dispatch_table(device)->GetShaderInstrumentationValuesARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetShaderInstrumentationValuesARM);
    if (strcmp(pName, "vkClearShaderInstrumentationMetricsARM") == 0 && (!device || device_dispatch_table(device)->ClearShaderInstrumentationMetricsARM))
        return reinterpret_cast<PFN_vkVoidFunction>(vkClearShaderInstrumentationMetricsARM);
    if (strcmp(pName, "vkCmdEndRendering2EXT") == 0 && (!device || device_dispatch_table(device)->CmdEndRendering2EXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdEndRendering2EXT);
    if (strcmp(pName, "vkCmdBeginCustomResolveEXT") == 0 && (!device || device_dispatch_table(device)->CmdBeginCustomResolveEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBeginCustomResolveEXT);
    if (strcmp(pName, "vkCmdSetComputeOccupancyPriorityNV") == 0 && (!device || device_dispatch_table(device)->CmdSetComputeOccupancyPriorityNV))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetComputeOccupancyPriorityNV);
    if (strcmp(pName, "vkCmdSetPrimitiveRestartIndexEXT") == 0 && (!device || device_dispatch_table(device)->CmdSetPrimitiveRestartIndexEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetPrimitiveRestartIndexEXT);
    if (strcmp(pName, "vkCreateAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CreateAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateAccelerationStructureKHR);
    if (strcmp(pName, "vkDestroyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->DestroyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkDestroyAccelerationStructureKHR);
    if (strcmp(pName, "vkCmdBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresKHR);
    if (strcmp(pName, "vkCmdBuildAccelerationStructuresIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdBuildAccelerationStructuresIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdBuildAccelerationStructuresIndirectKHR);
    if (strcmp(pName, "vkBuildAccelerationStructuresKHR") == 0 && (!device || device_dispatch_table(device)->BuildAccelerationStructuresKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkBuildAccelerationStructuresKHR);
    if (strcmp(pName, "vkCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureKHR);
    if (strcmp(pName, "vkCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyAccelerationStructureToMemoryKHR);
    if (strcmp(pName, "vkCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCopyMemoryToAccelerationStructureKHR);
    if (strcmp(pName, "vkWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->WriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkWriteAccelerationStructuresPropertiesKHR);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureKHR);
    if (strcmp(pName, "vkCmdCopyAccelerationStructureToMemoryKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyAccelerationStructureToMemoryKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyAccelerationStructureToMemoryKHR);
    if (strcmp(pName, "vkCmdCopyMemoryToAccelerationStructureKHR") == 0 && (!device || device_dispatch_table(device)->CmdCopyMemoryToAccelerationStructureKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdCopyMemoryToAccelerationStructureKHR);
    if (strcmp(pName, "vkGetAccelerationStructureDeviceAddressKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureDeviceAddressKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureDeviceAddressKHR);
    if (strcmp(pName, "vkCmdWriteAccelerationStructuresPropertiesKHR") == 0 && (!device || device_dispatch_table(device)->CmdWriteAccelerationStructuresPropertiesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdWriteAccelerationStructuresPropertiesKHR);
    if (strcmp(pName, "vkGetDeviceAccelerationStructureCompatibilityKHR") == 0 && (!device || device_dispatch_table(device)->GetDeviceAccelerationStructureCompatibilityKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetDeviceAccelerationStructureCompatibilityKHR);
    if (strcmp(pName, "vkGetAccelerationStructureBuildSizesKHR") == 0 && (!device || device_dispatch_table(device)->GetAccelerationStructureBuildSizesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetAccelerationStructureBuildSizesKHR);
    if (strcmp(pName, "vkCmdTraceRaysKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysKHR);
    if (strcmp(pName, "vkCreateRayTracingPipelinesKHR") == 0 && (!device || device_dispatch_table(device)->CreateRayTracingPipelinesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCreateRayTracingPipelinesKHR);
    if (strcmp(pName, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingCaptureReplayShaderGroupHandlesKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingCaptureReplayShaderGroupHandlesKHR);
    if (strcmp(pName, "vkCmdTraceRaysIndirectKHR") == 0 && (!device || device_dispatch_table(device)->CmdTraceRaysIndirectKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdTraceRaysIndirectKHR);
    if (strcmp(pName, "vkGetRayTracingShaderGroupStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->GetRayTracingShaderGroupStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkGetRayTracingShaderGroupStackSizeKHR);
    if (strcmp(pName, "vkCmdSetRayTracingPipelineStackSizeKHR") == 0 && (!device || device_dispatch_table(device)->CmdSetRayTracingPipelineStackSizeKHR))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdSetRayTracingPipelineStackSizeKHR);
    if (strcmp(pName, "vkCmdDrawMeshTasksEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksEXT);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectEXT);
    if (strcmp(pName, "vkCmdDrawMeshTasksIndirectCountEXT") == 0 && (!device || device_dispatch_table(device)->CmdDrawMeshTasksIndirectCountEXT))
        return reinterpret_cast<PFN_vkVoidFunction>(vkCmdDrawMeshTasksIndirectCountEXT);

    return nullptr;
}
