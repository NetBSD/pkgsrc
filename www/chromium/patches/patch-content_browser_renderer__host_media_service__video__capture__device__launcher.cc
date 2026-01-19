$NetBSD: patch-content_browser_renderer__host_media_service__video__capture__device__launcher.cc,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/media/service_video_capture_device_launcher.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/renderer_host/media/service_video_capture_device_launcher.cc
@@ -24,7 +24,7 @@
 #include "media/base/media_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
@@ -166,7 +166,7 @@ void ServiceVideoCaptureDeviceLauncher::
   }
 #else
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, additionally check whether the NV12 GPU memory buffer is
     // supported.
     if (GpuDataManagerImpl::GetInstance()->IsGpuMemoryBufferNV12Supported())
