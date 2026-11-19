$NetBSD: patch-content_browser_gpu_gpu__data__manager__impl.cc,v 1.33 2026/11/19 19:46:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_data_manager_impl.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl.cc
@@ -411,7 +411,7 @@ void GpuDataManagerImpl::OnDisplayMetric
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
