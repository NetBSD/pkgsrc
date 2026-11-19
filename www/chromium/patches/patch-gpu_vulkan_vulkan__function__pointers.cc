$NetBSD: patch-gpu_vulkan_vulkan__function__pointers.cc,v 1.33 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_function_pointers.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ gpu/vulkan/vulkan_function_pointers.cc
@@ -1297,7 +1297,7 @@ bool VulkanFunctionPointers::BindDeviceF
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (gfx::HasExtension(enabled_extensions,
                         VK_EXT_IMAGE_DRM_FORMAT_MODIFIER_EXTENSION_NAME)) {
     constexpr char kvkGetImageDrmFormatModifierPropertiesEXT[] =
@@ -1503,7 +1503,7 @@ void VulkanFunctionPointers::ResetForTes
   vkGetSwapchainImagesKHR = nullptr;
   vkQueuePresentKHR = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   vkGetImageDrmFormatModifierPropertiesEXT = nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
