$NetBSD: patch-device_vr_openxr_openxr__device.cc,v 1.6 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_device.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ device/vr/openxr/openxr_device.cc
@@ -90,7 +90,7 @@ OpenXrDevice::OpenXrDevice(
 
   // Only support WebGPU sessions if the feature flag is enabled; the Linux
   // Vulkan binding does not support WebGPU sessions yet.
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebXRWebGPUBinding)) {
     device_data.supported_features.emplace_back(
         mojom::XRSessionFeature::WEBGPU);
@@ -234,7 +234,7 @@ void OpenXrDevice::OnRequestSessionResul
   session_result->session = std::move(session);
   session_result->controller =
       exclusive_controller_receiver_.BindNewPipeAndPassRemote();
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // The in-headset overlay UI is not implemented on Linux; leaving the overlay
   // unset tells the browser to skip the VrUiHost.
   session_result->overlay = std::move(overlay);
