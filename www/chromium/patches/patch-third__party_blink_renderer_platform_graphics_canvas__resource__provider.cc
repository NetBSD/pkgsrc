$NetBSD: patch-third__party_blink_renderer_platform_graphics_canvas__resource__provider.cc,v 1.1 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/canvas_resource_provider.cc
@@ -1301,7 +1301,7 @@ CanvasResourceProvider::CreateSharedImag
           gpu::SHARED_IMAGE_USAGE_CONCURRENT_READ_WRITE);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   should_force_bgra8_to_rgba = true;
