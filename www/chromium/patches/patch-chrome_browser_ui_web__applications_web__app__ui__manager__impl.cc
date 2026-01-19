$NetBSD: patch-chrome_browser_ui_web__applications_web__app__ui__manager__impl.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -587,7 +587,7 @@ void WebAppUiManagerImpl::MaybeShowIPHPr
     Browser* browser,
     Profile* profile,
     const std::string& app_id) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WebAppProvider* provider = WebAppProvider::GetForWebApps(profile);
   CHECK(provider);
 
@@ -808,7 +808,7 @@ void WebAppUiManagerImpl::ClearWebAppSit
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
