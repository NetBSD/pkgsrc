$NetBSD: patch-components_services_paint__preview__compositor_paint__preview__compositor__collection__impl.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/services/paint_preview_compositor/paint_preview_compositor_collection_impl.cc
@@ -22,7 +22,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "content/public/child/font_integration_init.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #endif
 
@@ -79,7 +79,7 @@ PaintPreviewCompositorCollectionImpl::Pa
     // Initialize font access for Skia.
 #if BUILDFLAG(IS_WIN)
   content::InitializeFontIntegration();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   content::UtilityThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
