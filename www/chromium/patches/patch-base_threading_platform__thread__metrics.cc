$NetBSD: patch-base_threading_platform__thread__metrics.cc,v 1.9 2025/12/23 13:22:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_metrics.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ base/threading/platform_thread_metrics.cc
@@ -55,7 +55,7 @@ PlatformThreadMetrics::CreateForCurrentT
 }
 
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<PlatformThreadMetrics>
