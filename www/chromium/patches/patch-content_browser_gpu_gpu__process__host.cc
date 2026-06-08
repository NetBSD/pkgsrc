$NetBSD: patch-content_browser_gpu_gpu__process__host.cc,v 1.21 2026/06/08 13:12:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_process_host.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ content/browser/gpu/gpu_process_host.cc
@@ -286,6 +286,7 @@ static const char* const kSwitchNames[] 
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -310,7 +311,7 @@ static const char* const kSwitchNames[] 
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
