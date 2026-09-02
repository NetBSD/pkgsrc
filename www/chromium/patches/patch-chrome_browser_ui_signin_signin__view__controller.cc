$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller.cc,v 1.25 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -584,7 +584,7 @@ void SigninViewController::ShowModalSync
       GetOnModalDialogClosedCallback());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewController::ShowModalHistorySyncOptInDialog(
     bool should_close_modal_dialog,
     HistorySyncOptinHelper::FlowCompletedCallback callback) {
@@ -601,7 +601,7 @@ void SigninViewController::ShowModalHist
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
