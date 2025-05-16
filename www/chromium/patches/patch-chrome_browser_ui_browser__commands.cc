$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.2 2025/05/16 16:08:19 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -1980,7 +1980,7 @@ void OpenUpdateChromeDialog(Browser* bro
   } else if (UpgradeDetector::GetInstance()->is_outdated_install_no_au()) {
     UpgradeDetector::GetInstance()->NotifyOutdatedInstallNoAutoUpdate();
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
