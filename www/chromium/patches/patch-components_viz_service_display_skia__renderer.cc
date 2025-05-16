$NetBSD: patch-components_viz_service_display_skia__renderer.cc,v 1.2 2025/05/16 16:08:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/display/skia_renderer.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/viz/service/display/skia_renderer.cc
@@ -1391,7 +1391,7 @@ void SkiaRenderer::ClearFramebuffer() {
   if (current_frame()->current_render_pass->has_transparent_background) {
     ClearCanvas(SkColors::kTransparent);
   } else {
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // On DEBUG builds, opaque render passes are cleared to blue
     // to easily see regions that were not drawn on the screen.
     // ClearCavas() call causes slight pixel difference, so linux-ref and
