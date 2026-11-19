$NetBSD: patch-gpu_config_gpu__info__collector.cc,v 1.33 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_info_collector.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ gpu/config/gpu_info_collector.cc
@@ -366,7 +366,7 @@ void ReportWebGPUAdapterMetrics(dawn::na
 
 void ReportWebGPUSupportMetrics(dawn::native::Instance* instance) {
   static BASE_FEATURE(kCollectWebGPUSupportMetrics,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                       base::FEATURE_DISABLED_BY_DEFAULT);
 #else
                       base::FEATURE_ENABLED_BY_DEFAULT);
@@ -946,7 +946,7 @@ void CollectDawnInfo(const gpu::GpuPrefe
 #if BUILDFLAG(IS_WIN)
       {wgpu::FeatureLevel::Compatibility, wgpu::BackendType::D3D11},
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       {wgpu::FeatureLevel::Compatibility, wgpu::BackendType::OpenGL},
 #endif
   };
