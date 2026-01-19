$NetBSD: patch-chrome_browser_ui_tabs_features.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/tabs/features.cc
@@ -28,7 +28,7 @@ bool CanShowTabSearchPositionSetting() {
   }
 // Mac and other platforms will always have the tab search position in the
 // correct location, cros/linux/win git the user the option to change.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kTabSearchPositionSetting);
 #else
   return false;
