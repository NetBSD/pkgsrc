$NetBSD: patch-src_3rdparty_chromium_gpu_config_gpu__test__config.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/config/gpu_test_config.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_test_config.cc
@@ -25,7 +25,7 @@ namespace {
 GPUTestConfig::OS GetCurrentOS() {
 #if defined(OS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif defined(OS_WIN)
   int32_t major_version = 0;
