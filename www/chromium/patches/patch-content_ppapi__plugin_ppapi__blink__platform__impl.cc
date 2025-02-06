$NetBSD: patch-content_ppapi__plugin_ppapi__blink__platform__impl.cc,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/ppapi_plugin/ppapi_blink_platform_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/ppapi_plugin/ppapi_blink_platform_impl.cc
@@ -21,7 +21,7 @@
 
 #if BUILDFLAG(IS_MAC)
 #include "content/child/child_process_sandbox_support_impl_mac.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/child_process_sandbox_support_impl_linux.h"
 #include "mojo/public/cpp/bindings/pending_remote.h"
 #endif
@@ -36,7 +36,7 @@ typedef struct CGFont* CGFontRef;
 namespace content {
 
 PpapiBlinkPlatformImpl::PpapiBlinkPlatformImpl() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   mojo::PendingRemote<font_service::mojom::FontService> font_service;
   ChildThread::Get()->BindHostReceiver(
       font_service.InitWithNewPipeAndPassReceiver());
@@ -55,7 +55,7 @@ PpapiBlinkPlatformImpl::~PpapiBlinkPlatf
 void PpapiBlinkPlatformImpl::Shutdown() {}
 
 blink::WebSandboxSupport* PpapiBlinkPlatformImpl::GetSandboxSupport() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return sandbox_support_.get();
 #else
   return nullptr;
