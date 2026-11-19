$NetBSD: patch-device_vr_openxr_openxr__graphics__binding.cc,v 1.2 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_graphics_binding.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ device/vr/openxr/openxr_graphics_binding.cc
@@ -309,7 +309,7 @@ bool OpenXrGraphicsBinding::WaitOnBaseLa
   return WaitOnFence(*base_layer_, gpu_fence);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenXrGraphicsBinding::WaitOnImplicitFences(
     const std::vector<LayerId>& updated_layers) {
   if (layers_sequence_.empty()) {
@@ -565,7 +565,7 @@ bool OpenXrGraphicsBinding::CreateCompos
   if (!SupportsLayers()) {
     return false;
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The page's layer of an unsupported type never becomes active.
   if (!SupportsLayerType(OpenXrCompositionLayer::GetTypeFromMojomData(
           *layer_data->mutable_data->layer_data))) {
