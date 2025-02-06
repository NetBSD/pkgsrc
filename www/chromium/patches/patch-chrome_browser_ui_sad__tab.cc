$NetBSD: patch-chrome_browser_ui_sad__tab.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/sad_tab.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/sad_tab.cc
@@ -176,7 +176,7 @@ std::vector<int> SadTab::GetSubMessages(
       // Only show Incognito suggestion if not already in Incognito mode.
       if (!web_contents_->GetBrowserContext()->IsOffTheRecord())
         message_ids.insert(message_ids.begin(), IDS_SAD_TAB_RELOAD_INCOGNITO);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Note: on macOS, Linux and ChromeOS, the first bullet is either one of
       // IDS_SAD_TAB_RELOAD_CLOSE_TABS or IDS_SAD_TAB_RELOAD_CLOSE_NOTABS
       // followed by one of the above suggestions.
