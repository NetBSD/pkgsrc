$NetBSD: patch-src_3rdparty_chromium_content_renderer_renderer__blink__platform__impl.h,v 1.1 2025/12/21 09:38:28 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h
@@ -264,7 +264,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
                                    const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
