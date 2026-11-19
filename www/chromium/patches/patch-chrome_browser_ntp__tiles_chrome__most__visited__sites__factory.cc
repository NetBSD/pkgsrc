$NetBSD: patch-chrome_browser_ntp__tiles_chrome__most__visited__sites__factory.cc,v 1.26 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -49,7 +49,7 @@ bool ShouldCreatePopularSites(Profile* p
 }
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
