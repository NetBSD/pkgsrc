$NetBSD: patch-third__party_blink_renderer_modules_webgpu_gpu__canvas__context.cc,v 1.1 2025/05/16 16:08:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/blink/renderer/modules/webgpu/gpu_canvas_context.cc
@@ -207,7 +207,7 @@ bool GPUCanvasContext::PaintRenderingRes
 
   scoped_refptr<WebGPUMailboxTexture> front_buffer_texture;
   if (source_buffer == kFrontBuffer) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // By returning false here the canvas will show up as black in the scenarios
     // that copy the front buffer, such as printing.
     // TODO(crbug.com/40902474): Support concurrent SharedImage reads via Dawn
