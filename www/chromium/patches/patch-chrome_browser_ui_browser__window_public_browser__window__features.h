$NetBSD: patch-chrome_browser_ui_browser__window_public_browser__window__features.h,v 1.11 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/public/browser_window_features.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/browser_window/public/browser_window_features.h
@@ -112,7 +112,7 @@ class PinInfoBarController;
 }  // namespace default_browser
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ProfileCustomizationBubbleSyncController;
 namespace session_restore_infobar {
 class SessionRestoreInfobarController;
@@ -441,7 +441,7 @@ class BrowserWindowFeatures {
     return browser_select_file_dialog_controller_.get();
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ProfileCustomizationBubbleSyncController*
   profile_customization_bubble_sync_controller() {
     return profile_customization_bubble_sync_controller_.get();
@@ -632,7 +632,7 @@ class BrowserWindowFeatures {
   std::unique_ptr<BrowserSelectFileDialogController>
       browser_select_file_dialog_controller_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProfileCustomizationBubbleSyncController>
       profile_customization_bubble_sync_controller_;
 
