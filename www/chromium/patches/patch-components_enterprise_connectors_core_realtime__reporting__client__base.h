$NetBSD: patch-components_enterprise_connectors_core_realtime__reporting__client__base.h,v 1.1 2026/11/08 15:38:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/realtime_reporting_client_base.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/enterprise/connectors/core/realtime_reporting_client_base.h
@@ -115,7 +115,7 @@ class RealtimeReportingClientBase : publ
   // on Windows/Mac/Linux platforms. Regardless of collecting device signals or
   // not, this method is expected to call `UploadSecurityEvent()` in the
   // end.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   virtual void MaybeCollectDeviceSignalsAndReportEvent(
       ::chrome::cros::reporting::proto::Event event,
