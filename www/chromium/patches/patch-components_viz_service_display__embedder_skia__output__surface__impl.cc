$NetBSD: patch-components_viz_service_display__embedder_skia__output__surface__impl.cc,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1524,7 +1524,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::G
                                         VK_IMAGE_TILING_OPTIMAL, vk_format,
                                         si_format, image_context->color_space(),
                                         image_context->ycbcr_info());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,
