$NetBSD: patch-components_viz_service_frame__sinks_root__compositor__frame__sink__impl.cc,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc
@@ -113,7 +113,7 @@ RootCompositorFrameSinkImpl::Create(
   output_surface->SetNeedsSwapSizeNotifications(
       params->send_swap_size_notifications);
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // For X11, we need notify client about swap completion after resizing, so the
   // client can use it for synchronize with X11 WM.
   output_surface->SetNeedsSwapSizeNotifications(true);
@@ -792,7 +792,7 @@ void RootCompositorFrameSinkImpl::Displa
   if (display_client_ && enable_swap_completion_callback_) {
     display_client_->DidCompleteSwapWithSize(pixel_size);
   }
-#elif BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   if (display_client_ && pixel_size != last_swap_pixel_size_) {
     last_swap_pixel_size_ = pixel_size;
     display_client_->DidCompleteSwapWithNewSize(last_swap_pixel_size_);
