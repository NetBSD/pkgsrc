$NetBSD: patch-src_3rdparty_chromium_base_threading_platform__thread__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/threading/platform_thread_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/threading/platform_thread_unittest.cc
@@ -311,7 +311,7 @@ TEST(PlatformThreadTest,
 // and hardcodes what we know. Please inform scheduler-dev@chromium.org if this
 // proprerty changes for a given platform.
 TEST(PlatformThreadTest, CanIncreaseThreadPriority) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // On Ubuntu, RLIMIT_NICE and RLIMIT_RTPRIO are 0 by default, so we won't be
   // able to increase priority to any level.
   constexpr bool kCanIncreasePriority = false;
@@ -406,7 +406,7 @@ TEST(PlatformThreadTest, SetHugeThreadNa
 TEST(PlatformThreadTest, GetDefaultThreadStackSize) {
   size_t stack_size = PlatformThread::GetDefaultThreadStackSize();
 #if defined(OS_WIN) || defined(OS_IOS) || defined(OS_FUCHSIA) || \
-    ((defined(OS_LINUX) || defined(OS_CHROMEOS)) &&              \
+    ((defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)) && \
      !defined(THREAD_SANITIZER)) ||                              \
     (defined(OS_ANDROID) && !defined(ADDRESS_SANITIZER))
   EXPECT_EQ(0u, stack_size);
