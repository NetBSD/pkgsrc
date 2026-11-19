$NetBSD: patch-device_vr_openxr_openxr__render__loop.cc,v 1.2 2026/11/19 19:46:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_render_loop.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ device/vr/openxr/openxr_render_loop.cc
@@ -1047,7 +1047,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 
   // No GPU fence: a CPU finish guarantees the WebGL write completed before the
   // binding reads the shared image. WaitOnFence is a no-op without a fence FD.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The finish is only needed if the flushed write left no fence to wait on.
   gpu::ClientSharedImage::WaitSyncTokenAndSignal(
       std::move(shared_images), std::move(combined_sync_tokens), gl,
@@ -1065,7 +1065,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenXrRenderLoop::OnWebXrWritesFlushed(
     int16_t frame_index,
     std::vector<LayerId> updated_layers) {
