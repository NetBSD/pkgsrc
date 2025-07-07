$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller__delegate.h,v 1.3 2025/07/07 09:23:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller_delegate.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller_delegate.h
@@ -48,7 +48,7 @@ class SigninViewControllerDelegate {
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewControllerDelegate instance that
   // displays the modal history sync opt in dialog. The returned object should
   // delete itself when the window it's managing is closed.
@@ -87,7 +87,7 @@ class SigninViewControllerDelegate {
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the managed user notice modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
