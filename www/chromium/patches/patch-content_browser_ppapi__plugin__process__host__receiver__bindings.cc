$NetBSD: patch-content_browser_ppapi__plugin__process__host__receiver__bindings.cc,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/ppapi_plugin_process_host_receiver_bindings.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/ppapi_plugin_process_host_receiver_bindings.cc
@@ -8,7 +8,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -17,7 +17,7 @@ namespace content {
 
 void PpapiPluginProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>())
     ConnectToFontService(std::move(font_receiver));
 #endif
