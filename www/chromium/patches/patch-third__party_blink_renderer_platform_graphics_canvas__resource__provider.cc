$NetBSD: patch-third__party_blink_renderer_platform_graphics_canvas__resource__provider.cc,v 1.3 2026/03/14 12:40:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc
@@ -1200,7 +1200,7 @@ std::unique_ptr<T> CanvasResourceProvide
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
