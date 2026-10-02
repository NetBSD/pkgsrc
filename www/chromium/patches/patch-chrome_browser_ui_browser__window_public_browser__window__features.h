$NetBSD: patch-chrome_browser_ui_browser__window_public_browser__window__features.h,v 1.20 2026/10/02 11:43:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_window/public/browser_window_features.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/browser_window/public/browser_window_features.h
@@ -135,7 +135,7 @@ class ZoomBubbleManager;
 class WindowsTaskbarIconUpdater;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class ProfileCustomizationBubbleSyncController;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -237,7 +237,7 @@ namespace send_tab_to_self {
 class SendTabToSelfToolbarBubbleController;
 }  // namespace send_tab_to_self
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace session_restore_infobar {
 class SessionRestoreInfobarController;
 }  // namespace session_restore_infobar
@@ -637,7 +637,7 @@ class BrowserWindowFeatures {
       pin_infobar_controller_;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<ProfileCustomizationBubbleSyncController>
       profile_customization_bubble_sync_controller_;
   std::unique_ptr<session_restore_infobar::SessionRestoreInfobarController>
