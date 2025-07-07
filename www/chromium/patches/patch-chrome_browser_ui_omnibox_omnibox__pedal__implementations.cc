$NetBSD: patch-chrome_browser_ui_omnibox_omnibox__pedal__implementations.cc,v 1.3 2025/07/07 09:23:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -1985,7 +1985,7 @@ const gfx::VectorIcon& GetSharingHubVect
   return omnibox::kShareMacChromeRefreshIcon;
 #elif BUILDFLAG(IS_WIN)
   return omnibox::kShareWinChromeRefreshIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return omnibox::kShareLinuxChromeRefreshIcon;
 #else
   return omnibox::kShareChromeRefreshIcon;
