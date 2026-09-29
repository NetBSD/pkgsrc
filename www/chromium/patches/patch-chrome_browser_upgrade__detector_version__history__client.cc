$NetBSD: patch-chrome_browser_upgrade__detector_version__history__client.cc,v 1.26 2026/09/29 07:42:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -177,7 +177,7 @@ GURL GetVersionReleasesUrl(base::Version
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
