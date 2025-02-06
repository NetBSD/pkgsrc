$NetBSD: patch-content_renderer_renderer__blink__platform__impl.h,v 1.1 2025/02/06 09:58:08 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_blink_platform_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -254,7 +254,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
