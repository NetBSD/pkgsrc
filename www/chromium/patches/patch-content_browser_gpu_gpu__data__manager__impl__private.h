$NetBSD: patch-content_browser_gpu_gpu__data__manager__impl__private.h,v 1.27 2026/09/29 07:42:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_data_manager_impl_private.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl_private.h
@@ -155,7 +155,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -315,7 +315,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   bool application_is_visible_ = true;
 
   bool disable_gpu_compositing_ = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gpu_memory_buffer_NV12_supported_ = false;
 #endif  // BUILDFLAG(IS_LINUX)
 
