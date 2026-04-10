$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.17 2026/04/10 17:31:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -2388,7 +2388,7 @@ void OpenUpdateChromeDialog(Browser* bro
   } else if (detector->is_outdated_install_no_au()) {
     ShowOutdatedUpgradeBubble(browser, browser, /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
