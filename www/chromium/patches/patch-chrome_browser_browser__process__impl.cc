$NetBSD: patch-chrome_browser_browser__process__impl.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browser_process_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/browser_process_impl.cc
@@ -236,7 +236,7 @@
 #include "chrome/browser/ui/profiles/profile_picker.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/error_reporting/chrome_js_error_report_processor.h"  // nogncheck
 #endif
 
@@ -257,7 +257,7 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
 #endif
@@ -1125,7 +1125,7 @@ void BrowserProcessImpl::RegisterPrefs(P
                                 GoogleUpdateSettings::GetCollectStatsConsent());
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1308,7 +1308,7 @@ void BrowserProcessImpl::PreMainMessageL
 
   ApplyMetricsReportingPolicy();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChromeJsErrorReportProcessor::Create();
 #endif
 
@@ -1398,7 +1398,7 @@ void BrowserProcessImpl::PreMainMessageL
               features::kUseAppBoundEncryptionProviderForEncryption))));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kDbusSecretPortal)) {
     providers.emplace_back(
         /*precedence=*/10u,
@@ -1648,7 +1648,7 @@ void BrowserProcessImpl::Unpin() {
 // Mac is currently not supported.
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
