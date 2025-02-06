$NetBSD: patch-content_browser_gpu_gpu__memory__buffer__manager__singleton.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/gpu/gpu_memory_buffer_manager_singleton.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/gpu/gpu_memory_buffer_manager_singleton.cc
@@ -46,7 +46,7 @@ scoped_refptr<base::SingleThreadTaskRunn
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsGpuMemoryBufferNV12Supported() {
   static bool is_computed = false;
   static bool supported = false;
@@ -98,7 +98,7 @@ GpuMemoryBufferManagerSingleton::GetInst
 }
 
 void GpuMemoryBufferManagerSingleton::OnGpuExtraInfoUpdate() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Dynamic check whether the NV12 format is supported as it may be
   // inconsistent between the system GBM (Generic Buffer Management) and
   // chromium miniGBM.
