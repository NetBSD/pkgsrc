$NetBSD: patch-gpu_config_gpu__finch__features.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ gpu/config/gpu_finch_features.cc
@@ -122,7 +122,8 @@ BASE_FEATURE(kAllowHardwareBufferUsageFl
 // Android and Linux.
 BASE_FEATURE(kDefaultEnableGpuRasterization,
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || \
+    BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
