$NetBSD: patch-gpu_config_gpu__finch__features.cc,v 1.8 2025/10/16 19:43:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ gpu/config/gpu_finch_features.cc
@@ -125,7 +125,8 @@ BASE_FEATURE(AllowHardwareBufferUsageFla
 // Android and Linux.
 BASE_FEATURE(DefaultEnableGpuRasterization,
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
