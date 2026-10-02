$NetBSD: patch-device_vr_openxr_openxr__device.cc,v 1.2 2026/10/02 11:43:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_device.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ device/vr/openxr/openxr_device.cc
@@ -90,7 +90,7 @@ OpenXrDevice::OpenXrDevice(
 
   // Only support WebGPU sessions if the feature flag is enabled; the Linux
   // Vulkan binding does not support WebGPU sessions yet.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebXRWebGPUBinding)) {
     device_data.supported_features.emplace_back(
         mojom::XRSessionFeature::WEBGPU);
