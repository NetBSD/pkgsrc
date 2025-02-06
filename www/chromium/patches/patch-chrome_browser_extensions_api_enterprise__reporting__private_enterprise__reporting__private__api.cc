$NetBSD: patch-chrome_browser_extensions_api_enterprise__reporting__private_enterprise__reporting__private__api.cc,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.cc
@@ -42,7 +42,7 @@
 #include "components/reporting/util/statusor.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <optional>
 
 #include "base/strings/string_util.h"
@@ -160,7 +160,7 @@ api::enterprise_reporting_private::Conte
 }
 
 bool AllowClientCertificateReportingForUsers() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       enterprise_signals::features::kAllowClientCertificateReportingForUsers);
 #else
@@ -173,7 +173,7 @@ bool IsProfilePrefManaged(Profile* profi
   return pref && pref->IsManaged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 device_signals::SignalsAggregationRequest CreateAggregationRequest(
     device_signals::SignalName signal_name) {
@@ -235,7 +235,7 @@ EnterpriseReportingPrivateGetDeviceIdFun
 
 // getPersistentSecret
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 EnterpriseReportingPrivateGetPersistentSecretFunction::
     EnterpriseReportingPrivateGetPersistentSecretFunction() = default;
@@ -673,7 +673,7 @@ void EnterpriseReportingPrivateEnqueueRe
 }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // getFileSystemInfo
 
