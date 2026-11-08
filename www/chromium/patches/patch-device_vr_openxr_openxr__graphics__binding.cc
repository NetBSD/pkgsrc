$NetBSD: patch-device_vr_openxr_openxr__graphics__binding.cc,v 1.1 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_graphics_binding.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ device/vr/openxr/openxr_graphics_binding.cc
@@ -301,7 +301,7 @@ bool OpenXrGraphicsBinding::WaitOnBaseLa
   return WaitOnFence(*base_layer_, gpu_fence);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenXrGraphicsBinding::WaitOnImplicitFences(
     const std::vector<LayerId>& updated_layers) {
   if (layers_sequence_.empty()) {
