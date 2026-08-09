$NetBSD: patch-chrome_browser_ui_web__applications_web__app__ui__manager__impl.h,v 1.24 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.h
@@ -264,7 +264,7 @@ class WebAppUiManagerImpl : public Brows
       webapps::UninstallResultCode uninstall_code);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void ShowIPHPromoForAppsLaunchedViaLinkCapturing(Browser* browser,
                                                    const webapps::AppId& app_id,
                                                    bool is_activated);
