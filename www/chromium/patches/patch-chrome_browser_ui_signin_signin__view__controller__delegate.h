$NetBSD: patch-chrome_browser_ui_signin_signin__view__controller__delegate.h,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller_delegate.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller_delegate.h
@@ -85,7 +85,7 @@ class SigninViewControllerDelegate {
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the managed user notice modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
