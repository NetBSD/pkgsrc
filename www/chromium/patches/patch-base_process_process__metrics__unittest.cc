$NetBSD: patch-base_process_process__metrics__unittest.cc,v 1.1 2025/02/06 09:57:42 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/process/process_metrics_unittest.cc
@@ -62,7 +62,8 @@
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||      \
     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || \
+    BUILDFLAG(IS_BSD)
 #define ENABLE_CPU_TESTS 1
 #else
 #define ENABLE_CPU_TESTS 0
