$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.7 2025/09/12 16:02:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -2214,7 +2214,7 @@ void OpenUpdateChromeDialog(Browser* bro
   } else if (UpgradeDetector::GetInstance()->is_outdated_install_no_au()) {
     UpgradeDetector::GetInstance()->NotifyOutdatedInstallNoAutoUpdate();
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
