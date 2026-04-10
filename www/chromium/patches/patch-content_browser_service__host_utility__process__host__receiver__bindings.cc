$NetBSD: patch-content_browser_service__host_utility__process__host__receiver__bindings.cc,v 1.16 2026/04/10 17:31:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/service_host/utility_process_host_receiver_bindings.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ content/browser/service_host/utility_process_host_receiver_bindings.cc
@@ -10,7 +10,7 @@
 #include "content/public/common/content_client.h"
 #include "media/media_buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -24,7 +24,7 @@ namespace content {
 
 void UtilityProcessHost::BindHostReceiver(
     mojo::GenericPendingReceiver receiver) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
