$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_posix_signals.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/signals.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/posix/signals.cc
@@ -46,7 +46,7 @@ constexpr int kCrashSignals[] = {
 #if defined(SIGEMT)
     SIGEMT,
 #endif  // defined(SIGEMT)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
@@ -86,7 +86,7 @@ constexpr int kTerminateSignals[] = {
     SIGXCPU,
     SIGXFSZ,
 #endif  // defined(OS_APPLE)
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     SIGIO,
 #endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
 };
