$NetBSD: patch-third__party_blink_renderer_modules_webgl_webgl__rendering__context__base.cc,v 1.24 2026/08/09 06:31:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6684,7 +6684,7 @@ void WebGLRenderingContextBase::TexImage
   // unmultiply has been requested or we need to never premultiply for Image
   // creation from a VideoFrame.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1181562): TexSubImage2D via the GPU path performs poorly on
   // Linux when used with frames backed by SharedImages holding shared memory.
   // We don't have a way to differentiate this case from that of true texture
