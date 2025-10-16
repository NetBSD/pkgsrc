$NetBSD: patch-chrome_browser_ui_webui_side__panel_customize__chrome_customize__chrome__page__handler.h,v 1.4 2025/10/16 19:43:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.h
@@ -208,7 +208,7 @@ class CustomizeChromePageHandler
   // value needs to be requeried by the page.
   GURL last_source_url_{GURL(chrome::kChromeUINewTabPageURL)};
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PrefChangeRegistrar browser_pref_change_registrar_;
 #endif
   PrefChangeRegistrar pref_change_registrar_;
