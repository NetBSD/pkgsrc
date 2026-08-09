$NetBSD: patch-content_browser_devtools_devtools__frontend__host__impl.h,v 1.24 2026/08/09 06:31:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/devtools/devtools_frontend_host_impl.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ content/browser/devtools/devtools_frontend_host_impl.h
@@ -33,7 +33,7 @@ class DevToolsFrontendHostImpl : public 
 
   void BadMessageReceived() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnDidAddMessageToConsole(
       RenderFrameHost* source_frame,
       blink::mojom::ConsoleMessageLevel log_level,
