$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__data__manager__impl__private.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -1672,7 +1672,7 @@ void GpuDataManagerImplPrivate::RecordCo
   UMA_HISTOGRAM_ENUMERATION("GPU.CompositingMode", compositing_mode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImplPrivate::IsGpuMemoryBufferNV12Supported() {
   return is_gpu_memory_buffer_NV12_supported_;
 }
