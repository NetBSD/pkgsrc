$NetBSD: patch-src_3rdparty_chromium_content_renderer_renderer__blink__platform__impl.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.cc
@@ -97,7 +97,7 @@
 
 #if defined(OS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #endif
 
@@ -169,7 +169,7 @@ RendererBlinkPlatformImpl::RendererBlink
       main_thread_scheduler_(main_thread_scheduler) {
   // RenderThread may not exist in some tests.
   if (RenderThreadImpl::current()) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     mojo::PendingRemote<font_service::mojom::FontService> font_service;
     RenderThreadImpl::current()->BindHostReceiver(
         font_service.InitWithNewPipeAndPassReceiver());
@@ -179,7 +179,7 @@ RendererBlinkPlatformImpl::RendererBlink
 #endif
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   if (sandboxEnabled()) {
 #if defined(OS_MAC)
     sandbox_support_ = std::make_unique<WebSandboxSupportMac>();
@@ -232,7 +232,7 @@ RendererBlinkPlatformImpl::WrapSharedURL
 
 void RendererBlinkPlatformImpl::SetDisplayThreadPriority(
     base::PlatformThreadId thread_id) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (RenderThreadImpl* render_thread = RenderThreadImpl::current()) {
     render_thread->render_message_filter()->SetThreadPriority(
         thread_id, base::ThreadPriority::DISPLAY);
@@ -245,7 +245,7 @@ blink::BlameContext* RendererBlinkPlatfo
 }
 
 blink::WebSandboxSupport* RendererBlinkPlatformImpl::GetSandboxSupport() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD)
   return sandbox_support_.get();
 #else
   // These platforms do not require sandbox support.
