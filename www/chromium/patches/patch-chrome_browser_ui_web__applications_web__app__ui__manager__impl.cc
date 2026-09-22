$NetBSD: patch-chrome_browser_ui_web__applications_web__app__ui__manager__impl.cc,v 1.26 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/web_applications/web_app_ui_manager_impl.cc
@@ -348,7 +348,7 @@ bool WebAppUiManagerImpl::IsAppMigration
     return false;
   }
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   BrowserView* browser_view = BrowserView::GetBrowserViewForBrowser(window);
   return browser_view &&
          browser_view->GetProperty(kIsPwaUpdateDialogShowingKey) &&
@@ -1020,7 +1020,7 @@ void WebAppUiManagerImpl::ClearWebAppSit
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const base::Feature& GetPromoFeatureEngagementFromBrowser(
     const BrowserWindowInterface* browser) {
