$NetBSD: patch-components_performance__manager_decorators_process__metrics__decorator.cc,v 1.8 2025/10/16 19:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/performance_manager/decorators/process_metrics_decorator.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/performance_manager/decorators/process_metrics_decorator.cc
@@ -266,7 +266,7 @@ void ProcessMetricsDecorator::DidGetMemo
     base::ByteCount process_rss =
         base::KiB(process_dump_iter.os_dump().resident_set_kb);
     process_node->set_resident_set(process_rss);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     process_node->set_private_swap(
         base::KiB(process_dump_iter.os_dump().private_footprint_swap_kb));
 #endif
