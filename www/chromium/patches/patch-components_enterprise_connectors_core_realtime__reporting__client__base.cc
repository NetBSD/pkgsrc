$NetBSD: patch-components_enterprise_connectors_core_realtime__reporting__client__base.cc,v 1.31 2026/11/08 15:38:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/realtime_reporting_client_base.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/enterprise/connectors/core/realtime_reporting_client_base.cc
@@ -202,7 +202,7 @@ void RealtimeReportingClientBase::Report
     *event.mutable_time() = ToProtoTimestamp(base::Time::Now());
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MaybeCollectDeviceSignalsAndReportEvent(std::move(event), client, settings);
 #else
   // Regardless of collecting device signals or not, upload the security event
