$NetBSD: patch-components_viz_service_gl_gpu__service__impl.h,v 1.14 2026/03/14 12:40:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/gl/gpu_service_impl.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ components/viz/service/gl/gpu_service_impl.h
@@ -439,7 +439,7 @@ class VIZ_SERVICE_EXPORT GpuServiceImpl
 
   void OnBeginFrameOnIO(const BeginFrameArgs& args);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsGMBNV12Supported();
 #endif
 
