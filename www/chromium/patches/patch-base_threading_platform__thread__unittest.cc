$NetBSD: patch-base_threading_platform__thread__unittest.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/threading/platform_thread_unittest.cc
@@ -38,7 +38,7 @@
 #include "base/time/time.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <pthread.h>
 #include <sys/syscall.h>
 #include <sys/types.h>
@@ -362,7 +362,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanChangeThreadType) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level unless we are root (euid == 0).
   bool kCanIncreasePriority = false;
@@ -616,12 +616,16 @@ INSTANTIATE_TEST_SUITE_P(
 
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 namespace {
 
 bool IsTidCacheCorrect() {
+#if BUILDFLAG(IS_BSD)
+  return PlatformThread::CurrentId() == reinterpret_cast<int64_t>(pthread_self());
+#else
   return PlatformThread::CurrentId() == syscall(__NR_gettid);
+#endif
 }
 
 void* CheckTidCacheCorrectWrapper(void*) {
