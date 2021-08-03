$NetBSD: patch-src_3rdparty_chromium_base_security__unittest.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/security_unittest.cc.orig	2020-07-08 21:40:31.000000000 +0000
+++ src/3rdparty/chromium/base/security_unittest.cc
@@ -59,7 +59,7 @@ NOINLINE Type HideValueFromCompiler(vola
 // FAILS_ is too clunky.
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
