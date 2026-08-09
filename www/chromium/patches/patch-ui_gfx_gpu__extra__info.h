$NetBSD: patch-ui_gfx_gpu__extra__info.h,v 1.22 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_extra_info.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/gfx/gpu_extra_info.h
@@ -47,7 +47,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInf
   // applicable.
   ANGLEFeatures angle_features;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
