$NetBSD: patch-third__party_blink_renderer_platform_graphics_gpu_image__layer__bridge.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -47,7 +47,7 @@ scoped_refptr<StaticBitmapImage> MakeAcc
 
   const auto paint_image = source->PaintImageForCurrentFrame();
   const auto image_info = paint_image.GetSkImageInfo();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
