$NetBSD: patch-chrome_browser_ui_sad__tab.cc,v 1.24 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/sad_tab.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/sad_tab.cc
@@ -179,7 +179,7 @@ std::vector<int> SadTab::GetSubMessages(
       if (!web_contents_->GetBrowserContext()->IsOffTheRecord()) {
         message_ids.insert(message_ids.begin(), IDS_SAD_TAB_RELOAD_INCOGNITO);
       }
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Note: on macOS, Linux and ChromeOS, the first bullet is either one of
       // IDS_SAD_TAB_RELOAD_CLOSE_TABS or IDS_SAD_TAB_RELOAD_CLOSE_NOTABS
       // followed by one of the above suggestions.
