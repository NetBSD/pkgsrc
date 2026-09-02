$NetBSD: patch-content_renderer_renderer__blink__platform__impl.h,v 1.25 2026/09/02 13:13:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_blink_platform_impl.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ content/renderer/renderer_blink_platform_impl.h
@@ -289,7 +289,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
                                const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
