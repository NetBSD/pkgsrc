$NetBSD: patch-chrome_browser_glic_service_glic__instance__impl.cc,v 1.5 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -80,7 +80,7 @@
 #include "ui/base/l10n/l10n_util.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 
@@ -158,7 +158,7 @@ constexpr auto kImplicitInvocationSource
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
