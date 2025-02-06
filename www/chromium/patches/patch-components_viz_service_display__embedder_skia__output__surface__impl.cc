$NetBSD: patch-components_viz_service_display__embedder_skia__output__surface__impl.cc,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1498,7 +1498,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::G
                                             ->GetVulkanPhysicalDevice(),
                                         VK_IMAGE_TILING_OPTIMAL, vk_format,
                                         si_format, yuv_color_space, ycbcr_info);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,
