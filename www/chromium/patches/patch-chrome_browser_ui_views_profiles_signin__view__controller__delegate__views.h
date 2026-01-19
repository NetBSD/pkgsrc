$NetBSD: patch-chrome_browser_ui_views_profiles_signin__view__controller__delegate__views.h,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -58,7 +58,7 @@ class SigninViewControllerDelegateViews
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView> CreateHistorySyncOptInWebView(
       Browser* browser,
       bool should_close_modal_dialog,
@@ -84,7 +84,7 @@ class SigninViewControllerDelegateViews
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView>
   CreateManagedUserNoticeConfirmationWebView(
       Browser* browser,
@@ -155,7 +155,7 @@ class SigninViewControllerDelegateViews
       std::optional<int> dialog_width,
       InitializeSigninWebDialogUI initialize_signin_web_dialog_ui);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deletes the ephemeral profile when cancelling the local profile creation
   // dialog.
   void DeleteProfileOnCancel();
