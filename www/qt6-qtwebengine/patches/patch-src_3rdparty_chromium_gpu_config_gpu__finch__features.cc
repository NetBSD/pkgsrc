$NetBSD: patch-src_3rdparty_chromium_gpu_config_gpu__finch__features.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/config/gpu_finch_features.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_finch_features.cc
@@ -154,7 +154,8 @@ BASE_FEATURE(kAllowHardwareBufferUsageFl
 // DefaultEnableGpuRasterization has launched on Mac, Windows, ChromeOS,
 // Android and Linux.
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDefaultEnableGpuRasterization,
              "DefaultEnableGpuRasterization",
              base::FEATURE_ENABLED_BY_DEFAULT);
