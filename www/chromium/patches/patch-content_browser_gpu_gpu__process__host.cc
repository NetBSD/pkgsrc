$NetBSD: patch-content_browser_gpu_gpu__process__host.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_process_host.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/gpu/gpu_process_host.cc
@@ -275,6 +275,7 @@ static const char* const kSwitchNames[] 
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -302,7 +303,7 @@ static const char* const kSwitchNames[] 
     switches::kOzoneDumpFile,
     switches::kEnableNativeGpuMemoryBuffers,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
