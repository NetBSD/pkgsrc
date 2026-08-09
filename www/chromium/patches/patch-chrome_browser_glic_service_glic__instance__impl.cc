$NetBSD: patch-chrome_browser_glic_service_glic__instance__impl.cc,v 1.4 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -72,7 +72,7 @@
 #include "third_party/abseil-cpp/absl/functional/overload.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 
@@ -139,7 +139,7 @@ EmbedderKey CreateSidePanelEmbedderKey(t
 
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
