$NetBSD: patch-src_3rdparty_chromium_gpu_vulkan_vulkan__function__pointers.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.h
@@ -227,12 +227,12 @@ struct VulkanFunctionPointers {
       vkGetAndroidHardwareBufferPropertiesANDROIDFn;
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetSemaphoreFdKHR> vkGetSemaphoreFdKHRFn;
   VulkanFunction<PFN_vkImportSemaphoreFdKHR> vkImportSemaphoreFdKHRFn;
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   VulkanFunction<PFN_vkGetMemoryFdKHR> vkGetMemoryFdKHRFn;
   VulkanFunction<PFN_vkGetMemoryFdPropertiesKHR> vkGetMemoryFdPropertiesKHRFn;
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
@@ -447,14 +447,14 @@ struct VulkanFunctionPointers {
       ->vkGetAndroidHardwareBufferPropertiesANDROIDFn
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkGetSemaphoreFdKHRFn
 #define vkImportSemaphoreFdKHR \
   gpu::GetVulkanFunctionPointers()->vkImportSemaphoreFdKHRFn
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 #define vkGetMemoryFdKHR gpu::GetVulkanFunctionPointers()->vkGetMemoryFdKHRFn
 #define vkGetMemoryFdPropertiesKHR \
   gpu::GetVulkanFunctionPointers()->vkGetMemoryFdPropertiesKHRFn
@@ -493,4 +493,4 @@ struct VulkanFunctionPointers {
   gpu::GetVulkanFunctionPointers()->vkGetSwapchainImagesKHRFn
 #define vkQueuePresentKHR gpu::GetVulkanFunctionPointers()->vkQueuePresentKHRFn
 
-#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
\ No newline at end of file
+#endif  // GPU_VULKAN_VULKAN_FUNCTION_POINTERS_H_
