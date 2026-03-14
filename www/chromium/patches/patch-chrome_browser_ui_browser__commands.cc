$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.16 2026/03/14 12:40:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -2381,7 +2381,7 @@ void OpenUpdateChromeDialog(Browser* bro
   } else if (detector->is_outdated_install_no_au()) {
     ShowOutdatedUpgradeBubble(browser, browser, /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
