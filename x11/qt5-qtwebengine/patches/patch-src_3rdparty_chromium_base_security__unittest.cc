$NetBSD: patch-src_3rdparty_chromium_base_security__unittest.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/security_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/security_unittest.cc
@@ -61,7 +61,7 @@ NOINLINE Type HideValueFromCompiler(vola
 void OverflowTestsSoftExpectTrue(bool overflow_detected) {
   if (!overflow_detected) {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_APPLE)
+    defined(OS_APPLE) || defined(OS_BSD)
     // Sadly, on Linux, Android, and OSX we don't have a good story yet. Don't
     // fail the test, but report.
     printf("Platform has overflow: %s\n",
