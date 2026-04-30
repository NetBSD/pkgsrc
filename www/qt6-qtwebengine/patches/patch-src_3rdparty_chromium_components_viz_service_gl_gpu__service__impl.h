$NetBSD: patch-src_3rdparty_chromium_components_viz_service_gl_gpu__service__impl.h,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/viz/service/gl/gpu_service_impl.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/viz/service/gl/gpu_service_impl.h
@@ -456,7 +456,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
