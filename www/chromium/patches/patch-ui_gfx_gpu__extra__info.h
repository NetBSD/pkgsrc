$NetBSD: patch-ui_gfx_gpu__extra__info.h,v 1.12 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_extra_info.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/gfx/gpu_extra_info.h
@@ -47,7 +47,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInf
   // applicable.
   ANGLEFeatures angle_features;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
