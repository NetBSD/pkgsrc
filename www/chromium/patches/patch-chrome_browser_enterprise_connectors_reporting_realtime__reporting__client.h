$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_realtime__reporting__client.h,v 1.26 2026/09/22 13:41:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h
@@ -19,7 +19,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "components/policy/core/common/cloud/cloud_policy_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
 
@@ -97,7 +97,7 @@ class RealtimeReportingClient : public R
       const std::string& dm_token) override;
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(notyet)
   void MaybeCollectDeviceSignalsAndReportEvent(
       ::chrome::cros::reporting::proto::Event event,
       policy::CloudPolicyClient* client,
@@ -128,7 +128,7 @@ class RealtimeReportingClient : public R
   base::WeakPtrFactory<RealtimeReportingClient> weak_ptr_factory_{this};
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AddCrowdstrikeSignalsToEvent(
     ::chrome::cros::reporting::proto::Event& event,
     const device_signals::SignalsAggregationResponse& response);
