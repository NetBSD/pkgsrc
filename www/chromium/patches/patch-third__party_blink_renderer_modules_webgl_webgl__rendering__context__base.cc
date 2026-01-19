$NetBSD: patch-third__party_blink_renderer_modules_webgl_webgl__rendering__context__base.cc,v 1.14 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/modules/webgl/webgl_rendering_context_base.cc
@@ -6407,7 +6407,7 @@ void WebGLRenderingContextBase::TexImage
   // unmultiply has been requested or we need to never premultiply for Image
   // creation from a VideoFrame.
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1175907): Only TexImage2D seems to work with the GPU path on
   // Android M -- appears to work fine on R, but to avoid regressions in <video>
   // limit to TexImage2D only for now. Fails conformance test on Nexus 5X:
