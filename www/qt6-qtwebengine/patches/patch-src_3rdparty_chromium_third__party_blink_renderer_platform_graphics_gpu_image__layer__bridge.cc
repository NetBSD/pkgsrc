$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_graphics_gpu_image__layer__bridge.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/graphics/gpu/image_layer_bridge.cc
@@ -48,7 +48,7 @@ scoped_refptr<StaticBitmapImage> MakeAcc
 
   const auto paint_image = source->PaintImageForCurrentFrame();
   const auto image_info = paint_image.GetSkImageInfo();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
