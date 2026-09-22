$NetBSD: patch-third__party_blink_renderer_platform_graphics_gpu_webgpu__shared__image__wrapper__cache.cc,v 1.1 2026/09/22 13:41:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper_cache.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper_cache.cc
@@ -397,7 +397,7 @@ WebGpuSharedImageWrapperCache::LeaseWebG
       return nullptr;
     }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
     // dependent on canvas copies being RGBA (not BGRA).
     if (format != viz::SinglePlaneFormat::kRGBA_F16) {
