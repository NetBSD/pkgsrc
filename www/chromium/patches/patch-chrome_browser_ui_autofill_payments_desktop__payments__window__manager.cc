$NetBSD: patch-chrome_browser_ui_autofill_payments_desktop__payments__window__manager.cc,v 1.28 2026/10/02 11:43:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.cc
@@ -59,7 +59,7 @@ gfx::Size GetPopupSizeForBnpl() {
 DesktopPaymentsWindowManager::DesktopPaymentsWindowManager(
     ContentAutofillClient* client)
     : client_(CHECK_DEREF(client)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   scoped_observation_.Observe(
       ProfileBrowserCollection::GetForProfile(Profile::FromBrowserContext(
           client_->GetWebContents().GetBrowserContext())));
@@ -155,7 +155,7 @@ void DesktopPaymentsWindowManager::WebCo
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void DesktopPaymentsWindowManager::OnBrowserActivated(
     BrowserWindowInterface* browser) {
   // If there is an ongoing payments window manager pop-up flow, and the
