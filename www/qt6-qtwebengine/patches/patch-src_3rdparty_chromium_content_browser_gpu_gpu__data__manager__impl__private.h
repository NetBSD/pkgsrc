$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__data__manager__impl__private.h,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.h
@@ -147,7 +147,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   void OnDisplayMetricsChanged(const display::Display& display,
                                uint32_t changed_metrics);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGpuMemoryBufferNV12Supported();
   void SetGpuMemoryBufferNV12Supported(bool supported);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -311,7 +311,7 @@ class CONTENT_EXPORT GpuDataManagerImplP
   bool application_is_visible_ = true;
 
   bool disable_gpu_compositing_ = false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gpu_memory_buffer_NV12_supported_ = false;
 #endif  // BUILDFLAG(IS_LINUX)
 };
