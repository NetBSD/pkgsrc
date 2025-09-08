$NetBSD: patch-ui_gfx_gpu__extra__info.h,v 1.4 2025/09/08 13:24:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_extra_info.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/gfx/gpu_extra_info.h
@@ -51,7 +51,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInf
   std::vector<gfx::BufferUsageAndFormat> gpu_memory_buffer_support_x11;
 #endif  // BUILDFLAG(IS_OZONE_X11)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
