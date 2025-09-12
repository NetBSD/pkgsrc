$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller.cc,v 1.7 2025/09/12 16:02:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -476,7 +476,7 @@ void SigninViewController::ShowModalSync
       GetOnModalDialogClosedCallback());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewController::ShowModalHistorySyncOptInDialog() {
   CHECK(base::FeatureList::IsEnabled(switches::kEnableHistorySyncOptin));
   CloseModalSignin();
@@ -491,7 +491,7 @@ void SigninViewController::ShowModalHist
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
