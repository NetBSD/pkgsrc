$NetBSD: patch-chrome_browser_metrics_chrome__metrics__service__client.cc,v 1.24 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/chrome_metrics_service_client.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/metrics/chrome_metrics_service_client.cc
@@ -200,7 +200,7 @@
 #include "chrome/browser/metrics/power/power_metrics_provider_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/metrics/motherboard_metrics_provider.h"
 #endif
 
@@ -212,7 +212,7 @@
 #include "chrome/browser/metrics/bluetooth_metrics_provider.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/updates/update_metrics_provider.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -541,7 +541,7 @@ void ChromeMetricsServiceClient::Registe
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   metrics::structured::StructuredMetricsService::RegisterPrefs(registry);
 
 #if !BUILDFLAG(IS_CHROMEOS)
@@ -738,7 +738,7 @@ void ChromeMetricsServiceClient::Initial
         this, local_state);
   }
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   metrics::structured::Recorder::GetInstance()->SetUiTaskRunner(
       base::SequencedTaskRunner::GetCurrentDefault());
 #endif
@@ -798,7 +798,7 @@ void ChromeMetricsServiceClient::Registe
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::CPUMetricsProvider>());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<metrics::MotherboardMetricsProvider>());
 #endif
@@ -898,7 +898,7 @@ void ChromeMetricsServiceClient::Registe
       std::make_unique<GoogleUpdateMetricsProviderMac>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       std::make_unique<DesktopPlatformFeaturesMetricsProvider>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -1008,7 +1008,7 @@ void ChromeMetricsServiceClient::Registe
       std::make_unique<PowerMetricsProvider>());
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   metrics_service_->RegisterMetricsProvider(
       metrics::CreateDesktopSessionMetricsProvider());
   metrics_service_->RegisterMetricsProvider(
@@ -1214,7 +1214,7 @@ bool ChromeMetricsServiceClient::Registe
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This creates the DesktopProfileSessionDurationsServices if it didn't exist
   // already.
   metrics::DesktopProfileSessionDurationsServiceFactory::GetForBrowserContext(
@@ -1564,7 +1564,7 @@ void ChromeMetricsServiceClient::CreateS
   recorder =
       std::make_unique<metrics::structured::AshStructuredMetricsRecorder>(
           cros_system_profile_provider_.get());
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   // Make sure that Structured Metrics recording delegates have been created
   // before the service is created. This is handled in other places for ChromeOS
