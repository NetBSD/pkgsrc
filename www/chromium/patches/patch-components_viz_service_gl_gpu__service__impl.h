$NetBSD: patch-components_viz_service_gl_gpu__service__impl.h,v 1.28 2026/10/16 15:30:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.h.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.h
@@ -451,7 +451,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
