$NetBSD: patch-chrome_browser_ntp__tiles_chrome__most__visited__sites__factory.cc,v 1.8 2026/02/15 09:03:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ntp_tiles/chrome_most_visited_sites_factory.cc
@@ -59,7 +59,7 @@ bool ShouldCreateCustomLinksManager() {
 
 bool ShouldCreateEnterpriseShortcutsManager() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(ntp_tiles::kNtpEnterpriseShortcuts);
 #else
   return false;
