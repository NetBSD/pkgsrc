$NetBSD: patch-services_tracing_public_cpp_system__metrics__sampler.cc,v 1.16 2026/04/10 17:31:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/tracing/public/cpp/system_metrics_sampler.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ services/tracing/public/cpp/system_metrics_sampler.cc
@@ -176,8 +176,8 @@ void SystemMetricsSampler::ProcessSample
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"),
                   "PhysicalMemoryFootprint",
                   memory_info->physical_footprint_bytes);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)) && defined(notyet)
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"), "VmSwapMemory",
                   memory_info->vm_swap_bytes);
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"), "RssAnonMemory",
