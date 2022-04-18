$NetBSD: patch-src_3rdparty_chromium_base_task_thread__pool_environment__config__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/task/thread_pool/environment_config_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/task/thread_pool/environment_config_unittest.cc
@@ -15,7 +15,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 #if defined(OS_WIN) || defined(OS_APPLE)
   EXPECT_TRUE(CanUseBackgroundPriorityForWorkerThread());
 #elif defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_CHROMEOS) || defined(OS_NACL)
+    defined(OS_CHROMEOS) || defined(OS_NACL) || defined(OS_BSD)
   EXPECT_FALSE(CanUseBackgroundPriorityForWorkerThread());
 #else
 #error Platform doesn't match any block
