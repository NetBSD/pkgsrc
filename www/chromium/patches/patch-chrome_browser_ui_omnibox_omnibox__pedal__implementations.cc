$NetBSD: patch-chrome_browser_ui_omnibox_omnibox__pedal__implementations.cc,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/omnibox/omnibox_pedal_implementations.cc
@@ -2024,7 +2024,7 @@ const gfx::VectorIcon& GetSharingHubVect
   return features::IsRoundedIconsEnabled()
              ? omnibox::kShareWindowsIcon
              : omnibox::kShareWinChromeRefreshOldIcon;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return features::IsRoundedIconsEnabled()
              ? omnibox::kSendIcon
              : omnibox::kShareLinuxChromeRefreshOldIcon;
