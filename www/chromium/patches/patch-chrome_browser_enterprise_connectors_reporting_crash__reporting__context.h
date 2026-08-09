$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_crash__reporting__context.h,v 1.6 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.h
@@ -11,7 +11,7 @@
 #include "chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 #include "third_party/crashpad/crashpad/client/crash_report_database.h"
 #endif
 
@@ -30,7 +30,7 @@ class CrashReportingContext
   CrashReportingContext operator=(CrashReportingContext&&) = delete;
   ~CrashReportingContext() override;
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   static CrashReportingContext* GetInstance();
 
   void AddProfile(BrowserCrashEventRouter* router, Profile* profile);
@@ -54,7 +54,7 @@ class CrashReportingContext
 #endif
 };
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 // Utility function to parse reports from a crash database that were
 // created past a given timestamp. Included in header for testing.
