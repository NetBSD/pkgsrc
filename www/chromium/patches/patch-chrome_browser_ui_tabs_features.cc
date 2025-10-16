$NetBSD: patch-chrome_browser_ui_tabs_features.cc,v 1.8 2025/10/16 19:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/tabs/features.cc
@@ -64,7 +64,7 @@ bool CanShowTabSearchPositionSetting() {
   }
 // Mac and other platforms will always have the tab search position in the
 // correct location, cros/linux/win git the user the option to change.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kTabSearchPositionSetting);
 #else
   return false;
