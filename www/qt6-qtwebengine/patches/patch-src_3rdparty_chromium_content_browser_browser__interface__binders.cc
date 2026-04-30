$NetBSD: patch-src_3rdparty_chromium_content_browser_browser__interface__binders.cc,v 1.1 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/browser_interface_binders.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/content/browser/browser_interface_binders.cc
@@ -237,7 +237,7 @@
 #include "content/browser/xr/webxr_internals/webxr_internals_ui.h"
 #endif
 
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "content/public/browser/service_process_host.h"
 #else
 #include "content/browser/gpu/gpu_process_host.h"
@@ -274,7 +274,7 @@ shape_detection::mojom::ShapeDetectionSe
       mojo::Remote<shape_detection::mojom::ShapeDetectionService>>
       remote;
   if (!*remote) {
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     ServiceProcessHost::Launch<shape_detection::mojom::ShapeDetectionService>(
         remote->BindNewPipeAndPassReceiver(),
         ServiceProcessHost::Options()
