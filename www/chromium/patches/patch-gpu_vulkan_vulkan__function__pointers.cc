$NetBSD: patch-gpu_vulkan_vulkan__function__pointers.cc,v 1.13 2025/12/23 13:22:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_function_pointers.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -1297,7 +1297,7 @@ bool VulkanFunctionPointers::BindDeviceF
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME)) {
     constexpr char kvkGetImageDrmFormatModifierPropertiesEXT[] =
@@ -1498,7 +1498,7 @@ void VulkanFunctionPointers::ResetForTes
   vkGetSwapchainImagesKHR = nullptr;
   vkQueuePresentKHR = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   vkGetImageDrmFormatModifierPropertiesEXT = nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
