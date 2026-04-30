$NetBSD: patch-src_3rdparty_chromium_services_shape__detection_shape__detection__service.cc,v 1.1 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/shape_detection/shape_detection_service.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/services/shape_detection/shape_detection_service.cc
@@ -22,7 +22,7 @@
 #elif BUILDFLAG(IS_ANDROID)
 // No C++ code, barcode detection comes from Java.
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "services/shape_detection/barcode_detection_provider_chrome.h"
 #else
 #include "services/shape_detection/barcode_detection_provider_impl.h"
@@ -56,7 +56,7 @@ void ShapeDetectionService::BindBarcodeD
 #elif BUILDFLAG(IS_MAC)
   BarcodeDetectionProviderMac::Create(std::move(receiver));
 #elif BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   BarcodeDetectionProviderChrome::Create(std::move(receiver));
 #else
   BarcodeDetectionProviderImpl::Create(std::move(receiver));
