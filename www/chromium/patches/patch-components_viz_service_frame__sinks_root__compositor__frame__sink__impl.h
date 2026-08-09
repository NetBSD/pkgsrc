$NetBSD: patch-components_viz_service_frame__sinks_root__compositor__frame__sink__impl.h,v 1.24 2026/08/09 06:31:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -221,7 +221,7 @@ class VIZ_SERVICE_EXPORT RootCompositorF
   base::TimeDelta display_frame_interval_ = BeginFrameArgs::DefaultInterval();
   base::TimeDelta preferred_frame_interval_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
