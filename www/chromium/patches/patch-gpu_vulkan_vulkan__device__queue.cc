$NetBSD: patch-gpu_vulkan_vulkan__device__queue.cc,v 1.6 2025/09/08 13:24:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_device_queue.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ gpu/vulkan/vulkan_device_queue.cc
@@ -145,7 +145,7 @@ bool VulkanDeviceQueue::Initialize(
 
       // In dual-CPU cases, we cannot detect the active GPU correctly on Linux,
       // so don't select GPU device based on the |gpu_info|.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // If gpu_info is provided, the device should match it.
     if (gpu_info && (device_properties.vendorID != gpu_info->gpu.vendor_id ||
                      device_properties.deviceID != gpu_info->gpu.device_id)) {
@@ -292,7 +292,7 @@ bool VulkanDeviceQueue::Initialize(
   // Android, Fuchsia, Linux, and CrOS (VaapiVideoDecoder) need YCbCr sampler
   // support.
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!physical_device_info.feature_sampler_ycbcr_conversion) {
     LOG(ERROR) << "samplerYcbcrConversion is not supported.";
     return false;
