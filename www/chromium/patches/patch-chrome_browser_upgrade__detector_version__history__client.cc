$NetBSD: patch-chrome_browser_upgrade__detector_version__history__client.cc,v 1.5 2025/09/08 13:24:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/upgrade_detector/version_history_client.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/upgrade_detector/version_history_client.cc
@@ -175,7 +175,7 @@ GURL GetVersionReleasesUrl(base::Version
 #define CURRENT_PLATFORM "win"
 #endif
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #define CURRENT_PLATFORM "linux"
 
