$NetBSD: patch-third__party_blink_renderer_platform_graphics_gpu_webgpu__shared__image__cache.cc,v 1.3 2026/10/23 15:05:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_cache.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_cache.cc
@@ -147,7 +147,7 @@ WebGpuSharedImageCache::LeaseSharedImage
       return nullptr;
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
     // dependent on canvas copies being RGBA (not BGRA).
     if (format != viz::SinglePlaneFormat::kRGBA_F16) {
