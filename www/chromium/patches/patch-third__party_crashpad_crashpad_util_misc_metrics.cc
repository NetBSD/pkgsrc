$NetBSD: patch-third__party_crashpad_crashpad_util_misc_metrics.cc,v 1.3 2025/07/07 09:23:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/crashpad/crashpad/util/misc/metrics.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ third_party/crashpad/crashpad/util/misc/metrics.cc
@@ -25,7 +25,7 @@
 #define METRICS_OS_NAME "Win"
 #elif BUILDFLAG(IS_ANDROID)
 #define METRICS_OS_NAME "Android"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define METRICS_OS_NAME "Linux"
 #elif BUILDFLAG(IS_FUCHSIA)
 #define METRICS_OS_NAME "Fuchsia"
