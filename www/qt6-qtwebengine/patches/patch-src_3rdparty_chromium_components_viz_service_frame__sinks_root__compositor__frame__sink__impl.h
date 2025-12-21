$NetBSD: patch-src_3rdparty_chromium_components_viz_service_frame__sinks_root__compositor__frame__sink__impl.h,v 1.1 2025/12/21 09:38:25 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -231,7 +231,7 @@ class VIZ_SERVICE_EXPORT RootCompositorF
   // See comments on `EvictionHandler`.
   EvictionHandler eviction_handler_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
