$NetBSD: patch-third__party_blink_renderer_platform_graphics_canvas__resource__provider.cc,v 1.2 2026/02/15 09:04:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc
@@ -1182,7 +1182,7 @@ CanvasResourceProvider::CreateSharedImag
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
