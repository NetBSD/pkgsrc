$NetBSD: patch-device_vr_openxr_openxr__graphics__binding.h,v 1.1 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_graphics_binding.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ device/vr/openxr/openxr_graphics_binding.h
@@ -208,7 +208,7 @@ class OpenXrGraphicsBinding {
   // able to successfully schedule and perform the wait, and false otherwise.
   bool WaitOnBaseLayerFence(gfx::GpuFence& gpu_fence);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Waits on the fences that the shared images of `updated_layers` carry for
   // the writes to them. Returns false if there are none.
   bool WaitOnImplicitFences(const std::vector<LayerId>& updated_layers);
@@ -281,7 +281,7 @@ class OpenXrGraphicsBinding {
   virtual bool WaitOnFence(OpenXrCompositionLayer& layer,
                            gfx::GpuFence& gpu_fence) = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // As WaitOnImplicitFences(), for `layer`'s active shared image.
   virtual bool WaitOnImplicitFence(OpenXrCompositionLayer& layer) = 0;
 #endif
