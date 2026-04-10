$NetBSD: patch-base_threading_platform__thread__metrics.cc,v 1.13 2026/04/10 17:31:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_metrics.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/threading/platform_thread_metrics.cc
@@ -54,7 +54,7 @@ PlatformThreadMetrics::CreateForCurrentT
 }
 
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<PlatformThreadMetrics>
