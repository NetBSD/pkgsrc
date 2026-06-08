$NetBSD: patch-chrome_browser_glic_service_glic__instance__impl.cc,v 1.1 2026/06/08 13:12:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/service/glic_instance_impl.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/glic/service/glic_instance_impl.cc
@@ -18,7 +18,7 @@
 #include "chrome/browser/actor/actor_keyed_service_factory.h"
 #include "chrome/browser/background/glic/glic_launcher_configuration.h"
 #include "chrome/browser/browser_process.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_controller_factory.h"
 #endif
 #include "chrome/browser/glic/common/future_browser_features.h"
@@ -141,7 +141,7 @@ EmbedderKey CreateSidePanelEmbedderKey(t
 
 enterprise_reporting::SaasUsageReportingController*
 GetSaasUsageReportingController(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return enterprise_reporting::SaasUsageReportingControllerFactory::
       GetForProfile(profile);
 #else
