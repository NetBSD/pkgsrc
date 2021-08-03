$NetBSD: patch-src_3rdparty_chromium_components_services_paint__preview__compositor_paint__preview__compositor__collection__impl.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h
@@ -20,7 +20,7 @@
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -74,7 +74,7 @@ class PaintPreviewCompositorCollectionIm
                  std::unique_ptr<PaintPreviewCompositorImpl>>
       compositors_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
