$NetBSD: patch-src_3rdparty_chromium_components_services_paint__preview__compositor_paint__preview__compositor__collection__impl.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.h
@@ -20,7 +20,7 @@
 #include "mojo/public/cpp/bindings/pending_receiver.h"
 #include "mojo/public/cpp/bindings/receiver.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "third_party/skia/include/core/SkRefCnt.h"
 #endif
@@ -74,7 +74,7 @@ class PaintPreviewCompositorCollectionIm
                  std::unique_ptr<PaintPreviewCompositorImpl>>
       compositors_;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
