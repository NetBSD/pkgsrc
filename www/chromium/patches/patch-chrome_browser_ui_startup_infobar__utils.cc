$NetBSD: patch-chrome_browser_ui_startup_infobar__utils.cc,v 1.1 2025/10/16 19:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/startup/infobar_utils.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/startup/infobar_utils.cc
@@ -197,7 +197,7 @@ void AddInfoBarsIfNecessary(Browser* bro
     }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kSessionRestoreInfobar)) {
       // TODO(crbug.com/431828875): Instantiate and initialize the session
       // restore controller.
