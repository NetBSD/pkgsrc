$NetBSD: patch-src_3rdparty_chromium_components_metrics_system__memory__stats__recorder__linux.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/metrics/system_memory_stats_recorder_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/metrics/system_memory_stats_recorder_linux.cc
@@ -31,6 +31,7 @@ namespace metrics {
   UMA_HISTOGRAM_LINEAR(name, sample, 2500, 50)
 
 void RecordMemoryStats(RecordMemoryStatsType type) {
+#if !defined(OS_BSD)
 #if defined(OS_CHROMEOS) || BUILDFLAG(IS_LACROS)
   // Record graphics GEM object size in a histogram with 50 MB buckets.
   int mem_gpu_mb = 0;
@@ -98,6 +99,7 @@ void RecordMemoryStats(RecordMemoryStats
     }
 #endif
   }
+#endif
 }
 
 }  // namespace metrics
