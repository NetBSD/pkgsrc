$NetBSD: patch-content_browser_gpu_gpu__data__manager__impl__private.h,v 1.7 2025/09/12 16:02:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -149,7 +149,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -312,7 +312,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   bool application_is_visible_ = true;
 
   bool disable_gpu_compositing_ = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gpu_memory_buffer_NV12_supported_ = false;
 #endif  // BUILDFLAG(IS_LINUX)
 
