$NetBSD: patch-chrome_browser_ui_web__applications_web__app__ui__manager__impl.cc,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -583,7 +583,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPr
     Browser* browser,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -809,7 +809,7 @@ void WebAppUiManagerImpl::ClearWebAppSit
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebAppUiManagerImpl::ShowIPHPromoForAppsLaunchedViaLinkCapturing(
     const Browser* browser,
     const webapps::AppId& app_id,
