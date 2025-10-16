$NetBSD: patch-content_browser_shape__detection_shape__detection__service__host.cc,v 1.1 2025/10/16 19:43:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/shape_detection/shape_detection_service_host.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ content/browser/shape_detection/shape_detection_service_host.cc
@@ -15,7 +15,7 @@
 #endif
 
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
 #include "content/public/browser/service_process_host.h"
 #else
 #include "content/browser/gpu/gpu_process_host.h"
@@ -29,7 +29,7 @@ shape_detection::mojom::ShapeDetectionSe
       remote;
   if (!*remote) {
 #if BUILDFLAG(IS_WIN) || (BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)))
+                          (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)))
     ServiceProcessHost::Launch<shape_detection::mojom::ShapeDetectionService>(
         remote->BindNewPipeAndPassReceiver(),
         ServiceProcessHost::Options()
