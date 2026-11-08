$NetBSD: patch-third__party_blink_renderer_platform_graphics_accelerated__static__bitmap__image.cc,v 1.1 2026/11/08 15:39:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/accelerated_static_bitmap_image.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/accelerated_static_bitmap_image.cc
@@ -155,7 +155,7 @@ scoped_refptr<StaticBitmapImage> Acceler
   bool should_force_bgra8_to_rgba =
       !shared_image_usage_flags.Has(gpu::SHARED_IMAGE_USAGE_WEBGPU_READ);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
