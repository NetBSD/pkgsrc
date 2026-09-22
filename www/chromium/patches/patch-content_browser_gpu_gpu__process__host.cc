$NetBSD: patch-content_browser_gpu_gpu__process__host.cc,v 1.26 2026/09/22 13:41:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_process_host.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ content/browser/gpu/gpu_process_host.cc
@@ -291,6 +291,7 @@ static const char* const kSwitchNames[] 
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -315,7 +316,7 @@ static const char* const kSwitchNames[] 
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
