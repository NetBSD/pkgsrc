$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__memory__buffer__manager__singleton.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/gpu/gpu_memory_buffer_manager_singleton.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_memory_buffer_manager_singleton.cc
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
