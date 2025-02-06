$NetBSD: patch-services_video__capture_video__capture__service__impl.h,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/video_capture/video_capture_service_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ services/video_capture/video_capture_service_impl.h
@@ -28,7 +28,7 @@
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "services/viz/public/cpp/gpu/gpu.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC)
@@ -77,7 +77,7 @@ class VideoCaptureServiceImpl : public m
   void OnGpuInfoUpdate(const CHROME_LUID& luid) override;
 #endif
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void SetVizGpu(std::unique_ptr<viz::Gpu> viz_gpu);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_MAC)
@@ -123,7 +123,7 @@ class VideoCaptureServiceImpl : public m
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class VizGpuContextProvider;
   std::unique_ptr<VizGpuContextProvider> viz_gpu_context_provider_;
   std::unique_ptr<viz::Gpu> viz_gpu_;
