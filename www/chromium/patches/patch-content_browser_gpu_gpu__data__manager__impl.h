$NetBSD: patch-content_browser_gpu_gpu__data__manager__impl.h,v 1.23 2026/07/08 13:42:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_data_manager_impl.h.orig	2026-07-06 22:58:46.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl.h
@@ -234,7 +234,7 @@ class CONTENT_EXPORT GpuDataManagerImpl 
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics) override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
