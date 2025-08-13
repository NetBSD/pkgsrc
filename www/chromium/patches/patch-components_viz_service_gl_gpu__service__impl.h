$NetBSD: patch-components_viz_service_gl_gpu__service__impl.h,v 1.3 2025/08/13 07:44:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.h
@@ -487,7 +487,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
