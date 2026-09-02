$NetBSD: patch-third__party_blink_renderer_modules_canvas_imagebitmap_image__bitmap__rendering__context.cc,v 1.2 2026/09/02 13:13:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/blink/renderer/modules/canvas/imagebitmap/image_bitmap_rendering_context.cc
@@ -70,7 +70,7 @@ scoped_refptr<StaticBitmapImage> ImageBi
     return source;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(b/330865436): On Linux, CanvasResourceProvider doesn't always check
   // for SCANOUT support correctly on X11 and it's never supported in
   // practice. Therefore, don't include it until this flow is reworked.
