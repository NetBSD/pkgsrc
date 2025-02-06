$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_browser__crash__event__router.cc,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/browser_crash_event_router.cc
@@ -13,7 +13,7 @@ namespace enterprise_connectors {
 
 BrowserCrashEventRouter::BrowserCrashEventRouter(
     content::BrowserContext* context) {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   Profile* profile = Profile::FromBrowserContext(context);
@@ -23,7 +23,7 @@ BrowserCrashEventRouter::BrowserCrashEve
 }
 
 BrowserCrashEventRouter::~BrowserCrashEventRouter() {
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
   CrashReportingContext* crash_reporting_context =
       CrashReportingContext::GetInstance();
   crash_reporting_context->RemoveProfile(this);
