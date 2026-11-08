$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_realtime__reporting__client.h,v 1.32 2026/11/08 15:38:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h
@@ -19,7 +19,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "components/policy/core/common/cloud/cloud_policy_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
 
@@ -93,7 +93,7 @@ class RealtimeReportingClient : public R
   std::pair<std::string, policy::CloudPolicyClient*> InitProfileReportingClient(
       const std::string& dm_token) override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeCollectDeviceSignalsAndReportEvent(
       ::chrome::cros::reporting::proto::Event event,
       policy::CloudPolicyClient* client,
@@ -133,7 +133,7 @@ class RealtimeReportingClient : public R
   base::WeakPtrFactory<RealtimeReportingClient> weak_ptr_factory_{this};
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void AddCrowdstrikeSignalsToEvent(
     ::chrome::cros::reporting::proto::Event& event,
     const device_signals::SignalsAggregationResponse& response);
