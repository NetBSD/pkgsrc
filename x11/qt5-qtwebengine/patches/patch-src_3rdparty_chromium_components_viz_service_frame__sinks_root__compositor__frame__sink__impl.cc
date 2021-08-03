$NetBSD: patch-src_3rdparty_chromium_components_viz_service_frame__sinks_root__compositor__frame__sink__impl.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/components/viz/service/frame_sinks/root_compositor_frame_sink_impl.cc
@@ -431,7 +431,7 @@ void RootCompositorFrameSinkImpl::Displa
 #if defined(OS_ANDROID)
   if (display_client_)
     display_client_->DidCompleteSwapWithSize(pixel_size);
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (display_client_ && pixel_size != last_swap_pixel_size_) {
     last_swap_pixel_size_ = pixel_size;
     display_client_->DidCompleteSwapWithNewSize(last_swap_pixel_size_);
