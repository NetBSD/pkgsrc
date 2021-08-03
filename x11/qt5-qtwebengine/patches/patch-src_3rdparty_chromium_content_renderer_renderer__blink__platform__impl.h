$NetBSD: patch-src_3rdparty_chromium_content_renderer_renderer__blink__platform__impl.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h
@@ -31,7 +31,7 @@
 #include "third_party/blink/public/mojom/cache_storage/cache_storage.mojom.h"
 #include "third_party/blink/public/mojom/loader/code_cache.mojom.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -222,7 +222,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
 
   scoped_refptr<base::SingleThreadTaskRunner> io_runner_;
 
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -246,7 +246,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
   mojo::PendingRemote<blink::mojom::CodeCacheHost> code_cache_host_remote_;
   mojo::SharedRemote<blink::mojom::CodeCacheHost> code_cache_host_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
