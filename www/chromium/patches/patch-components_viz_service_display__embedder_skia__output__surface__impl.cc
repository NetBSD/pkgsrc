$NetBSD: patch-components_viz_service_display__embedder_skia__output__surface__impl.cc,v 1.3 2025/07/07 09:23:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display_embedder/skia_output_surface_impl.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/viz/service/display_embedder/skia_output_surface_impl.cc
@@ -1503,7 +1503,7 @@ GrBackendFormat SkiaOutputSurfaceImpl::G
                                             ->GetVulkanPhysicalDevice(),
                                         VK_IMAGE_TILING_OPTIMAL, vk_format,
                                         si_format, yuv_color_space, ycbcr_info);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // Textures that were allocated _on linux_ with ycbcr info came from
     // VaapiVideoDecoder, which exports using DRM format modifiers.
     return GrBackendFormats::MakeVk(gr_ycbcr_info,
