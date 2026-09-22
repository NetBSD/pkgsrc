$NetBSD: patch-chrome_browser_ui_web__applications_web__app__ui__manager__impl.h,v 1.26 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -271,7 +271,7 @@ class WebAppUiManagerImpl : public Brows
       webapps::UninstallResultCode uninstall_code);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(
       BrowserWindowInterface* browser,
       const webapps::AppId& app_id,
