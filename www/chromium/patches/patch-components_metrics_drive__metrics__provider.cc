$NetBSD: patch-components_metrics_drive__metrics__provider.cc,v 1.5 2025/09/08 13:24:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/drive_metrics_provider.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/metrics/drive_metrics_provider.cc
@@ -21,7 +21,7 @@
 namespace metrics {
 
 namespace {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RecordTriStateMetric(const char* name, std::optional<bool> sample) {
   base::UmaHistogramEnumeration(
       name, !sample.has_value()
@@ -106,7 +106,7 @@ void DriveMetricsProvider::FillDriveMetr
     drive->set_has_seek_penalty(*response.has_seek_penalty);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RecordTriStateMetric("UMA.DriveIsRemovableResult", response.is_removable);
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
