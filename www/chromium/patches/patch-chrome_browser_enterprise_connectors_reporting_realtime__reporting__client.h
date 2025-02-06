$NetBSD: patch-chrome_browser_enterprise_connectors_reporting_realtime__reporting__client.h,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/enterprise/connectors/reporting/realtime_reporting_client.h
@@ -17,7 +17,7 @@
 #include "components/keyed_service/core/keyed_service.h"
 #include "components/policy/core/common/cloud/cloud_policy_client.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/signals_types.h"
 #endif
 
@@ -165,7 +165,7 @@ class RealtimeReportingClient : public K
   base::WeakPtrFactory<RealtimeReportingClient> weak_ptr_factory_{this};
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Populate event dict with CrowdStrike signal values. If those signals are
 // available in `response`, this function returns a Dict with the following
 // fields added:
