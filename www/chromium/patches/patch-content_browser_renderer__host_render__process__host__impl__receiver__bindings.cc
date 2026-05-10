$NetBSD: patch-content_browser_renderer__host_render__process__host__impl__receiver__bindings.cc,v 1.19 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/renderer_host/render_process_host_impl_receiver_bindings.cc
@@ -56,7 +56,7 @@
 #include "content/browser/renderer_host/p2p/socket_dispatcher_host.h"
 #endif  // BUILDFLAG(IS_P2P_ENABLED)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
 #include "content/browser/font_service.h"  // nogncheck
 #endif
@@ -78,7 +78,7 @@
 #include "content/public/common/font_cache_win.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font_data/font_data_service_impl.h"
 #endif
 
@@ -345,7 +345,7 @@ void RenderProcessHostImpl::IOThreadHost
     }
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (features::IsFontDataServiceEnabled()) {
     if (auto font_data_receiver =
             receiver.As<font_data_service::mojom::FontDataService>()) {
@@ -356,7 +356,7 @@ void RenderProcessHostImpl::IOThreadHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
@@ -384,7 +384,7 @@ void RenderProcessHostImpl::IOThreadHost
   }
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (auto r = receiver.As<mojom::ThreadTypeSwitcher>()) {
     child_thread_type_switcher_.Bind(std::move(r));
     return;
