$NetBSD: patch-chrome_browser_ui_omnibox_omnibox__pedal__implementations.cc,v 1.19 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2002,7 +2002,7 @@ const gfx::VectorIcon& GetSharingHubVect
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
