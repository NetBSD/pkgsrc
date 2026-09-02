$NetBSD: patch-chrome_browser_enterprise_reporting_cloud__profile__reporting__service.cc,v 1.16 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -36,7 +36,7 @@
 #include "chrome/browser/enterprise/reporting/reporting_delegate_factory_desktop.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/browser_launch/browser_launch_event_controller_factory_desktop.h"
 #include "chrome/browser/enterprise/reporting/saas_usage/saas_usage_reporting_delegate_factory_desktop.h"
 #include "components/enterprise/browser/reporting/reporting_features.h"
@@ -119,7 +119,7 @@ void CloudProfileReportingService::Creat
 #endif
   report_scheduler_ = std::make_unique<ReportScheduler>(std::move(params));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kSaasUsageReporting)) {
     auto saas_usage_reporting_delegate_factory =
         SaasUsageReportingDelegateFactoryDesktop::CreateForProfile(profile_);
