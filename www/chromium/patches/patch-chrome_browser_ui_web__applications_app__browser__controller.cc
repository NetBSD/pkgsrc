$NetBSD: patch-chrome_browser_ui_web__applications_app__browser__controller.cc,v 1.23 2026/10/23 15:05:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -582,7 +582,7 @@ std::u16string AppBrowserController::Get
   // web bundle. The flash text is not needed on platforms that already display
   // the app name in the title bar (e.g. Mac, Windows, and Linux).
   if (IsIsolatedWebApp()) {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return std::u16string();
 #else   // !(BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX))
     return GetAppShortName();
