$NetBSD: patch-third__party_blink_renderer_modules_webgpu_gpu__queue.cc,v 1.19 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -1010,7 +1010,7 @@ bool GPUQueue::CopyFromCanvasSourceImage
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(crbug.com/dawn/1969): Some Android devices don't fail to copy from
