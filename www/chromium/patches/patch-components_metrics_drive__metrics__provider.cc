$NetBSD: patch-components_metrics_drive__metrics__provider.cc,v 1.17 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/drive_metrics_provider.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/metrics/drive_metrics_provider.cc
@@ -20,7 +20,7 @@
 namespace metrics {
 
 namespace {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RecordTriStateMetric(const char* name, std::optional<bool> sample) {
   base::UmaHistogramEnumeration(
       name, !sample.has_value()
@@ -105,7 +105,7 @@ void DriveMetricsProvider::FillDriveMetr
     drive->set_has_seek_penalty(*response.has_seek_penalty);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RecordTriStateMetric("UMA.DriveIsRemovableResult", response.is_removable);
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
