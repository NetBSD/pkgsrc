$NetBSD: patch-chrome_browser_enterprise_reporting_cloud__profile__reporting__service__factory.cc,v 1.1 2025/07/07 09:23:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service_factory.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service_factory.cc
@@ -10,7 +10,7 @@
 #include "components/enterprise/browser/reporting/report_scheduler.h"
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
@@ -48,7 +48,7 @@ CloudProfileReportingServiceFactory::Clo
                                  ProfileSelections::BuildForRegularProfile()) {
   DependsOn(enterprise::ProfileIdServiceFactory::GetInstance());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Depends on this service because
   // `CloudProfileReportingService.profile_request_generator_` has a dependency
   // on it.
