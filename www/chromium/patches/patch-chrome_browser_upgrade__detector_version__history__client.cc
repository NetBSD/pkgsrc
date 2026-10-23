$NetBSD: patch-chrome_browser_upgrade__detector_version__history__client.cc,v 1.30 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -177,7 +177,7 @@ GURL GetVersionReleasesUrl(base::Version
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
