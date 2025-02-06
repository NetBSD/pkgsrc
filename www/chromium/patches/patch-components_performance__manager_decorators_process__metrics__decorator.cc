$NetBSD: patch-components_performance__manager_decorators_process__metrics__decorator.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/performance_manager/decorators/process_metrics_decorator.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/performance_manager/decorators/process_metrics_decorator.cc
@@ -264,7 +264,7 @@ void ProcessMetricsDecorator::DidGetMemo
     // RSS and PMF to each node proportionally to its V8 heap size.
     uint64_t process_rss = process_dump_iter.os_dump().resident_set_kb;
     process_node->set_resident_set_kb(process_rss);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     process_node->set_private_swap_kb(
         process_dump_iter.os_dump().private_footprint_swap_kb);
 #endif
