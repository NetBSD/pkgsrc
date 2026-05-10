$NetBSD: patch-third__party_blink_renderer_modules_webgpu_gpu.cc,v 1.6 2026/05/10 15:30:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/webgpu/gpu.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ third_party/blink/renderer/modules/webgpu/gpu.cc
@@ -427,7 +427,7 @@ V8GPUTextureFormat GPU::getPreferredCanv
 }
 
 wgpu::TextureFormat GPU::GetPreferredCanvasFormat() {
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Interop of vulkan and GL has mesa driver bugs for BGRA format
   // See anglebug.com/40644739
   return wgpu::TextureFormat::RGBA8Unorm;
