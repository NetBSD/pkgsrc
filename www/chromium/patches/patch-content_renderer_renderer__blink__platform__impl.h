$NetBSD: patch-content_renderer_renderer__blink__platform__impl.h,v 1.33 2026/11/19 19:46:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_blink_platform_impl.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -290,7 +290,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
                                const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
