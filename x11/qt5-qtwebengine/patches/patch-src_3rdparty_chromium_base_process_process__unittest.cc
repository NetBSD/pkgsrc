$NetBSD: patch-src_3rdparty_chromium_base_process_process__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_unittest.cc
@@ -153,7 +153,7 @@ TEST_F(ProcessTest, CreationTimeOtherPro
   // was spawned and a time recorded after it was spawned. However, since the
   // base::Time and process creation clocks don't match, tolerate some error.
   constexpr base::TimeDelta kTolerance =
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // On Linux, process creation time is relative to boot time which has a
       // 1-second resolution. Tolerate 1 second for the imprecise boot time and
       // 100 ms for the imprecise clock.
