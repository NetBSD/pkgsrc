$NetBSD: patch-chrome_browser_upgrade__detector_version__history__client.cc,v 1.21 2026/07/06 13:06:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -177,7 +177,7 @@ GURL GetVersionReleasesUrl(base::Version
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
