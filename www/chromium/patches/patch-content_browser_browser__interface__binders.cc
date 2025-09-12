$NetBSD: patch-content_browser_browser__interface__binders.cc,v 1.3 2025/09/12 16:02:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_interface_binders.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ content/browser/browser_interface_binders.cc
@@ -234,7 +234,7 @@
 #include "content/browser/xr/webxr_internals/webxr_internals_ui.h"
 #endif
 
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "content/public/browser/service_process_host.h"
 #else
 #include "content/browser/gpu/gpu_process_host.h"
@@ -271,7 +271,7 @@ shape_detection::mojom::ShapeDetectionSe
       mojo::Remote<shape_detection::mojom::ShapeDetectionService>>
       remote;
   if (!*remote) {
-#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX))
+#if BUILDFLAG(GOOGLE_CHROME_BRANDING) && (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
     ServiceProcessHost::Launch<shape_detection::mojom::ShapeDetectionService>(
         remote->BindNewPipeAndPassReceiver(),
         ServiceProcessHost::Options()
