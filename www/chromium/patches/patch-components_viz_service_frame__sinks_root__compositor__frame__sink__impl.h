$NetBSD: patch-components_viz_service_frame__sinks_root__compositor__frame__sink__impl.h,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -231,7 +231,7 @@ class VIZ_SERVICE_EXPORT RootCompositorF
   // See comments on `EvictionHandler`.
   EvictionHandler eviction_handler_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
