$NetBSD: patch-chrome_browser_ui_webui__browser_webui__browser__window.cc,v 1.16 2026/06/01 10:09:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui_browser/webui_browser_window.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/ui/webui_browser/webui_browser_window.cc
@@ -59,7 +59,7 @@ const char* const kWebUIBrowserWindowKey
 
 // Copied from chrome/browser/ui/views/frame/browser_widget.cc.
 bool IsUsingLinuxSystemTheme(Profile* profile) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme();
 #else
   return false;
