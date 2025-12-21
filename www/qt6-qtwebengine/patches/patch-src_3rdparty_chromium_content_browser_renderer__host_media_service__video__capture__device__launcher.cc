$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_media_service__video__capture__device__launcher.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/renderer_host/media/service_video_capture_device_launcher.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/media/service_video_capture_device_launcher.cc
@@ -25,7 +25,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
@@ -173,7 +173,7 @@ void ServiceVideoCaptureDeviceLauncher::
   }
 #else
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, additionally check whether the NV12 GPU memory buffer is
     // supported.
     if (GpuDataManagerImpl::GetInstance()->IsGpuMemoryBufferNV12Supported())
