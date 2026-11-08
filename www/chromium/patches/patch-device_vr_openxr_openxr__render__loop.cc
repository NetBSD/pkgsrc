$NetBSD: patch-device_vr_openxr_openxr__render__loop.cc,v 1.1 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_render_loop.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ device/vr/openxr/openxr_render_loop.cc
@@ -982,7 +982,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 
   // No GPU fence: a CPU finish guarantees the WebGL write completed before the
   // binding reads the shared image. WaitOnFence is a no-op without a fence FD.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40286368): wait through ClientSharedImage once it can wait
   // on the sync tokens without the finish.
   for (const auto& sync_token : combined_sync_tokens) {
@@ -1006,7 +1006,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnI
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenXrRenderLoop::OnWebXrWritesFlushed(
     int16_t frame_index,
     std::vector<LayerId> updated_layers) {
