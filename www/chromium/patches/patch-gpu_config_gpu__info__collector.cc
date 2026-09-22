$NetBSD: patch-gpu_config_gpu__info__collector.cc,v 1.26 2026/09/22 13:41:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_info_collector.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ gpu/config/gpu_info_collector.cc
@@ -363,7 +363,7 @@ void ReportWebGPUAdapterMetrics(dawn::na
 
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_DISABLED_BY_DEFAULT);
 #else
                       base::FEATURE_ENABLED_BY_DEFAULT);
