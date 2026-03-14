$NetBSD: patch-gpu_config_gpu__test__config.cc,v 1.16 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_test_config.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ gpu/config/gpu_test_config.cc
@@ -27,7 +27,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif BUILDFLAG(IS_WIN)
   int32_t major_version = 0;
