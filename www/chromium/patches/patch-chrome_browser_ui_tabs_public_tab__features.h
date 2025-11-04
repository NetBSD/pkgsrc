$NetBSD: patch-chrome_browser_ui_tabs_public_tab__features.h,v 1.1 2025/11/04 14:55:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/public/tab_features.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/ui/tabs/public/tab_features.h
@@ -118,7 +118,7 @@ class TabContextualizationController;
 }  // namespace lens
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace wallet {
 class ChromeWalletablePassClient;
 }  // namespace wallet
@@ -451,7 +451,7 @@ class TabFeatures {
       bookmarkbar_preload_pipeline_manager_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<wallet::ChromeWalletablePassClient> walletable_pass_client_;
 #endif
   // Must be the last member.
