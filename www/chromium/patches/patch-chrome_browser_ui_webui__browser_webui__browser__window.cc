$NetBSD: patch-chrome_browser_ui_webui__browser_webui__browser__window.cc,v 1.21 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -73,7 +73,7 @@ const char* const kWebUIBrowserWindowKey
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
