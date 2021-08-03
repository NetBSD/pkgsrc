$NetBSD: patch-src_3rdparty_chromium_components_services_paint__preview__compositor_paint__preview__compositor__collection__impl.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc
@@ -15,7 +15,7 @@
 
 #if defined(OS_WIN)
 #include "content/public/child/dwrite_font_proxy_init_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #endif
 
@@ -35,7 +35,7 @@ PaintPreviewCompositorCollectionImpl::Pa
     // Initialize font access for Skia.
 #if defined(OS_WIN)
   content::InitializeDWriteFontProxy();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   content::UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -54,7 +54,7 @@ PaintPreviewCompositorCollectionImpl::Pa
   // encoding to PNG or we could provide our own codec implementations.
 
   // Sanity check that fonts are working.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // No WebSandbox is provided on Linux so the local fonts aren't accessible.
   // This is fine since since the subsetted fonts are provided in the SkPicture.
   // However, we still need to check that the SkFontMgr starts as it is used by
