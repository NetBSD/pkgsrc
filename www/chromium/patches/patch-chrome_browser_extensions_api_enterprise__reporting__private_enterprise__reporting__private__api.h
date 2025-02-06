$NetBSD: patch-chrome_browser_extensions_api_enterprise__reporting__private_enterprise__reporting__private__api.h,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/api/enterprise_reporting_private/enterprise_reporting_private_api.h
@@ -20,7 +20,7 @@
 #include "components/reporting/proto/synced/record.pb.h"
 #include "components/reporting/proto/synced/record_constants.pb.h"
 #include "components/reporting/util/statusor.h"
-#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "components/device_signals/core/browser/signals_types.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
@@ -56,7 +56,7 @@ class EnterpriseReportingPrivateGetDevic
   ~EnterpriseReportingPrivateGetDeviceIdFunction() override;
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetPersistentSecretFunction
     : public ExtensionFunction {
@@ -266,7 +266,7 @@ class EnterpriseReportingPrivateEnqueueR
 
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 class EnterpriseReportingPrivateGetFileSystemInfoFunction
     : public ExtensionFunction {
