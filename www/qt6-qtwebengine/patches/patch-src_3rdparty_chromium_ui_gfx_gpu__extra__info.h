$NetBSD: patch-src_3rdparty_chromium_ui_gfx_gpu__extra__info.h,v 1.1 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/gfx/gpu_extra_info.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/gpu_extra_info.h
@@ -51,7 +51,7 @@ struct COMPONENT_EXPORT(GFX) GpuExtraInf
   std::vector<gfx::BufferUsageAndFormat> gpu_memory_buffer_support_x11;
 #endif  // BUILDFLAG(IS_OZONE_X11)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_gmb_nv12_supported = false;
 #endif
 };
