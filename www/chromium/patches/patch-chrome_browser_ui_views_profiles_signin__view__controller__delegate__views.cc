$NetBSD: patch-chrome_browser_ui_views_profiles_signin__view__controller__delegate__views.cc,v 1.5 2025/08/13 07:44:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -63,14 +63,14 @@
 #include "chrome/browser/ui/webui/signin/signout_confirmation/signout_confirmation_ui.h"
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin_ui.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 namespace {
 
 const int kModalDialogWidth = 448;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const int kManagedUserNoticeConfirmationDialogWidth = 512;
 const int kManagedUserNoticeConfirmationDialogHeight = 576;
 const int kManagedUserNoticeConfirmationUpdatedDialogWidth = 780;
@@ -139,7 +139,7 @@ SigninViewControllerDelegateViews::Creat
       kSyncConfirmationDialogWidth, InitializeSigninWebDialogUI(true));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateHistorySyncOptInWebView(
     Browser* browser) {
@@ -225,7 +225,7 @@ SigninViewControllerDelegateViews::Creat
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateManagedUserNoticeConfirmationWebView(
@@ -410,7 +410,7 @@ SigninViewControllerDelegateViews::Signi
 
   SetButtons(static_cast<int>(ui::mojom::DialogButton::kNone));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the local profile creation dialog, cancelling the dialog (for instance
   // through the VKEY_ESCAPE accelerator) should delete the profile.
   if (delete_profile_on_cancel) {
@@ -502,7 +502,7 @@ void SigninViewControllerDelegateViews::
   content_view_->RequestFocus();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewControllerDelegateViews::DeleteProfileOnCancel() {
   ProfileAttributesEntry* entry =
       g_browser_process->profile_manager()
@@ -542,7 +542,7 @@ SigninViewControllerDelegate::CreateSync
       /*animate_on_resize=*/true);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateSyncHistoryOptInDelegate(Browser* browser) {
@@ -596,7 +596,7 @@ SigninViewControllerDelegate::CreateSign
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
