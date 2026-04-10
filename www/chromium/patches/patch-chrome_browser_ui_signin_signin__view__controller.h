$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller.h,v 1.15 2026/04/10 17:31:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller.h
@@ -171,7 +171,7 @@ class SigninViewController {
   void ShowModalSyncConfirmationDialog(bool is_signin_intercept,
                                        bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Shows the modal history sync opt in dialog as a browser-modal dialog on top
   // of the `browser_`'s window. Executes the provided callback when the dialog
   // closes.
