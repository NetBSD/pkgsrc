$NetBSD: patch-components_enterprise_connectors_core_realtime__reporting__client__base.cc,v 1.23 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/realtime_reporting_client_base.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/enterprise/connectors/core/realtime_reporting_client_base.cc
@@ -198,7 +198,7 @@ void RealtimeReportingClientBase::Report
     *event.mutable_time() = ToProtoTimestamp(base::Time::Now());
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   MaybeCollectDeviceSignalsAndReportEvent(std::move(event), client, settings);
 #else
   // Regardless of collecting device signals or not, upload the security event
@@ -320,7 +320,7 @@ void RealtimeReportingClientBase::Report
   if (include_profile_user_name) {
     event.Set(kKeyProfileUserName, GetProfileUserName());
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   MaybeCollectDeviceSignalsAndReportEventDeprecated(std::move(event), client,
                                                     name, settings, time);
 #else
