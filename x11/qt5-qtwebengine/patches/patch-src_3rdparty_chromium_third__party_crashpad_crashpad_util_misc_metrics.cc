$NetBSD: patch-src_3rdparty_chromium_third__party_crashpad_crashpad_util_misc_metrics.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/metrics.cc.orig	2020-07-15 18:56:30.000000000 +0000
+++ src/3rdparty/chromium/third_party/crashpad/crashpad/util/misc/metrics.cc
@@ -25,7 +25,7 @@
 #define METRICS_OS_NAME "Win"
 #elif defined(OS_ANDROID)
 #define METRICS_OS_NAME "Android"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define METRICS_OS_NAME "Linux"
 #elif defined(OS_FUCHSIA)
 #define METRICS_OS_NAME "Fuchsia"
