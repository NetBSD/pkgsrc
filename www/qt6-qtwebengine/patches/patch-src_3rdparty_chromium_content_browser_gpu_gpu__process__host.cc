$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__process__host.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -246,7 +246,7 @@ static const char* const kSwitchNames[] 
 #if BUILDFLAG(IS_WIN)
     sandbox::policy::switches::kAllowThirdPartyModules,
 #endif
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
     switches::kDisableDevShmUsage,
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -275,6 +275,7 @@ static const char* const kSwitchNames[] 
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -303,7 +304,7 @@ static const char* const kSwitchNames[] 
     switches::kOzoneDumpFile,
     switches::kEnableNativeGpuMemoryBuffers,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
