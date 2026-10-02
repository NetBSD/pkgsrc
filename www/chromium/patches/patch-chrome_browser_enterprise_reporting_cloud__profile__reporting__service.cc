$NetBSD: patch-chrome_browser_enterprise_reporting_cloud__profile__reporting__service.cc,v 1.19 2026/10/02 11:43:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -39,7 +39,7 @@
 #include "chrome/browser/enterprise/reporting/reporting_delegate_factory_desktop.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/browser_launch/browser_launch_event_controller_factory_desktop.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
@@ -126,7 +126,7 @@ void CloudProfileReportingService::Creat
         "profile", saas_usage_reporting_delegate_factory.get());
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kBrowserLaunchMetadataReporting)) {
     browser_launch_controller_ =
         BrowserLaunchEventControllerFactoryDesktop::CreateForProfile(profile_);
