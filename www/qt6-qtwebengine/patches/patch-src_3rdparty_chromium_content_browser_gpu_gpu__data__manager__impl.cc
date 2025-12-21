$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__data__manager__impl.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.cc
@@ -402,7 +402,7 @@ void GpuDataManagerImpl::OnDisplayMetric
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
