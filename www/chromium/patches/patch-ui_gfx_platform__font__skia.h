$NetBSD: patch-ui_gfx_platform__font__skia.h,v 1.2 2026/09/02 13:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/platform_font_skia.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/gfx/platform_font_skia.h
@@ -101,7 +101,7 @@ class COMPONENT_EXPORT(GFX) PlatformFont
   int font_size_pixels_;
   int style_;
   float device_scale_factor_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool subpixel_rendering_enabled_ = true;
 #endif
 
