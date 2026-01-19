$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller__delegate.h,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller_delegate.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller_delegate.h
@@ -50,7 +50,7 @@ class SigninViewControllerDelegate {
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewControllerDelegate instance that
   // displays the modal history sync opt in dialog. The returned object should
   // delete itself when the window it's managing is closed.
@@ -93,7 +93,7 @@ class SigninViewControllerDelegate {
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the managed user notice modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
