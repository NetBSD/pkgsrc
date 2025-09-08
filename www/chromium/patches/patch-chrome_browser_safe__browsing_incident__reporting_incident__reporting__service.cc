$NetBSD: patch-chrome_browser_safe__browsing_incident__reporting_incident__reporting__service.cc,v 1.6 2025/09/08 13:24:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/safe_browsing/incident_reporting/incident_reporting_service.cc
@@ -693,7 +693,7 @@ void IncidentReportingService::OnEnviron
 
 // Process::Current().CreationTime() is missing on some platforms.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::TimeDelta uptime =
       first_incident_time_ - base::Process::Current().CreationTime();
   environment_data->mutable_process()->set_uptime_msec(uptime.InMilliseconds());
