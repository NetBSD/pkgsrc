$NetBSD: patch-components_viz_service_gl_gpu__service__impl.h,v 1.5 2025/09/12 16:02:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.h
@@ -450,7 +450,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
