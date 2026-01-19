$NetBSD: patch-content_browser_shape__detection_shape__detection__service.cc,v 1.4 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/shape_detection/shape_detection_service.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/shape_detection/shape_detection_service.cc
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
