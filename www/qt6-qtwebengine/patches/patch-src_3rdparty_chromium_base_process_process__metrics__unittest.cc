$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics__unittest.cc,v 1.1 2025/12/21 09:38:15 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/process/process_metrics_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_metrics_unittest.cc
@@ -62,7 +62,8 @@
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||      \
     BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_APPLE) || \
+    BUILDFLAG(IS_BSD)
 #define ENABLE_CPU_TESTS 1
 #else
 #define ENABLE_CPU_TESTS 0
