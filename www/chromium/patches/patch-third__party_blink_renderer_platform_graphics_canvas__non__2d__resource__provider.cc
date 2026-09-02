$NetBSD: patch-third__party_blink_renderer_platform_graphics_canvas__non__2d__resource__provider.cc,v 1.1 2026/09/02 13:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/canvas_non_2d_resource_provider.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/canvas_non_2d_resource_provider.cc
@@ -98,7 +98,7 @@ CanvasNon2DResourceProvider::Create(
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
