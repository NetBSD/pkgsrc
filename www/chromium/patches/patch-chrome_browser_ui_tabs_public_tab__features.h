$NetBSD: patch-chrome_browser_ui_tabs_public_tab__features.h,v 1.25 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/tabs/public/tab_features.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/tabs/public/tab_features.h
@@ -335,13 +335,13 @@ class TabContextualizationController;
 
 namespace metrics {
 class MetricsServicesWebContentsObserver;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class DesktopSessionDurationObserver;
 #endif
 }  // namespace metrics
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace wallet {
 class ChromeWalletablePassClient;
 }  // namespace wallet
@@ -836,7 +836,7 @@ class TabFeatures {
       page_context_eligibility_helper_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<wallet::ChromeWalletablePassClient> walletable_pass_client_;
 #endif
 
@@ -851,13 +851,13 @@ class TabFeatures {
   std::unique_ptr<skills::SkillsUpdateObserver> skills_update_observer_;
 #endif  //  !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<metrics::DesktopSessionDurationObserver>
       desktop_session_duration_observer_;
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<enterprise_reporting::SaasUsageNavigationObserver>
       saas_usage_navigation_observer_;
   std::unique_ptr<HatsHelper> hats_helper_;
