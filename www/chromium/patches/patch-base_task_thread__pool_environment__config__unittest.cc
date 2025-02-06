$NetBSD: patch-base_task_thread__pool_environment__config__unittest.cc,v 1.1 2025/02/06 09:57:42 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/task/thread_pool/environment_config_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/task/thread_pool/environment_config_unittest.cc
@@ -15,7 +15,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE)
   EXPECT_TRUE(CanUseBackgroundThreadTypeForWorkerThread());
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseBackgroundThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
@@ -24,7 +24,7 @@ TEST(ThreadPoolEnvironmentConfig, CanUse
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID)
   EXPECT_TRUE(CanUseUtilityThreadTypeForWorkerThread());
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   EXPECT_FALSE(CanUseUtilityThreadTypeForWorkerThread());
 #else
 #error Platform doesn't match any block
