$NetBSD: patch-src_3rdparty_chromium_gpu_config_gpu__test__config.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/config/gpu_test_config.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_test_config.cc
@@ -29,7 +29,7 @@ GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   return GPUTestConfig::kOsChromeOS;
 #elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_OPENBSD)
+    BUILDFLAG(IS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif BUILDFLAG(IS_WIN)
   int32_t major_version = 0;
