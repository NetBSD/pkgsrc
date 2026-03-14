$NetBSD: patch-base_process_process__metrics__unittest.cc,v 1.16 2026/03/14 12:40:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_unittest.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ base/process/process_metrics_unittest.cc
@@ -59,7 +59,8 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || \
+    BUILDFLAG(IS_BSD)
 #define ENABLE_CPU_TESTS 1
 #else
 #define ENABLE_CPU_TESTS 0
