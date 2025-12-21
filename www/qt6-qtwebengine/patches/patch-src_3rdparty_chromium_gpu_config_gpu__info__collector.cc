$NetBSD: patch-src_3rdparty_chromium_gpu_config_gpu__info__collector.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/config/gpu_info_collector.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/gpu/config/gpu_info_collector.cc
@@ -358,7 +358,7 @@ void ReportWebGPUAdapterMetrics(dawn::na
 }
 
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
                       "CollectWebGPUSupportMetrics",
                       base::FEATURE_DISABLED_BY_DEFAULT);
