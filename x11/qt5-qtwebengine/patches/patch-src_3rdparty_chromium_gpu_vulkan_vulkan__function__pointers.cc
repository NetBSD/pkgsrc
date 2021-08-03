$NetBSD: patch-src_3rdparty_chromium_gpu_vulkan_vulkan__function__pointers.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_function_pointers.cc
@@ -828,7 +828,7 @@ bool VulkanFunctionPointers::BindDeviceF
   }
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME)) {
     vkGetSemaphoreFdKHRFn = reinterpret_cast<PFN_vkGetSemaphoreFdKHR>(
@@ -849,7 +849,7 @@ bool VulkanFunctionPointers::BindDeviceF
   }
 #endif  // defined(OS_LINUX) || defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME)) {
     vkGetMemoryFdKHRFn = reinterpret_cast<PFN_vkGetMemoryFdKHR>(
