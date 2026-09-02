$NetBSD: patch-chrome_browser_ui_sad__tab.cc,v 1.25 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/sad_tab.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/sad_tab.cc
@@ -175,7 +175,7 @@ std::vector<int> SadTab::GetSubMessages(
       if (!web_contents_->GetBrowserContext()->IsOffTheRecord()) {
         message_ids.insert(message_ids.begin(), IDS_SAD_TAB_RELOAD_INCOGNITO);
       }
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Note: on macOS, Linux and ChromeOS, the first bullet is either one of
       // IDS_SAD_TAB_RELOAD_CLOSE_TABS or IDS_SAD_TAB_RELOAD_CLOSE_NOTABS
       // followed by one of the above suggestions.
