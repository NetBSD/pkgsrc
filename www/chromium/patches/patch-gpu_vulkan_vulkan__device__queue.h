$NetBSD: patch-gpu_vulkan_vulkan__device__queue.h,v 1.24 2026/08/09 06:31:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_device_queue.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ gpu/vulkan/vulkan_device_queue.h
@@ -189,7 +189,7 @@ class COMPONENT_EXPORT(VULKAN) VulkanDev
 #endif
 
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   VkPhysicalDeviceSamplerYcbcrConversionFeatures
       sampler_ycbcr_conversion_features_{
           VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES};
