$NetBSD: patch-chrome_browser_ui_tabs_features.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/features.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/tabs/features.cc
@@ -48,7 +48,7 @@ BASE_FEATURE(kTabStripCollectionStorage,
 bool CanShowTabSearchPositionSetting() {
 // Mac and other platforms will always have the tab search position in the
 // correct location, cros/linux/win git the user the option to change.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kTabSearchPositionSetting);
 #else
   return false;
