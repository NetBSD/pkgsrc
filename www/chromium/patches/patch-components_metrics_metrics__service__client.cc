$NetBSD: patch-components_metrics_metrics__service__client.cc,v 1.4 2026/10/13 13:16:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/metrics_service_client.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ components/metrics/metrics_service_client.cc
@@ -39,7 +39,7 @@ struct LogTrimmingDefaults {
 };
 
 constexpr LogTrimmingDefaults GetLogTrimmingDefaults() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return {
       .initial_log_count_trim_threshold = 20,
       .ongoing_log_count_trim_threshold = 8,
