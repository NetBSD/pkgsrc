$NetBSD: patch-third__party_blink_renderer_platform_graphics_gpu_image__layer__bridge.cc,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -49,7 +49,7 @@ scoped_refptr<StaticBitmapImage> MakeAcc
   const auto paint_image = source->PaintImageForCurrentFrame();
   const auto image_info = paint_image.GetSkImageInfo().makeWH(
       source->Size().width(), source->Size().height());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
