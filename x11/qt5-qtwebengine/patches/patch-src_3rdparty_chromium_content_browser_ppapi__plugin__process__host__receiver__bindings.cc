$NetBSD: patch-src_3rdparty_chromium_content_browser_ppapi__plugin__process__host__receiver__bindings.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/ppapi_plugin_process_host_receiver_bindings.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/ppapi_plugin_process_host_receiver_bindings.cc
@@ -8,7 +8,7 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -17,7 +17,7 @@ namespace content {
 
 void PpapiPluginProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>())
     ConnectToFontService(std::move(font_receiver));
 #endif
