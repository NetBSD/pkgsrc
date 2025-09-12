$NetBSD: patch-services_shape__detection_shape__detection__service.cc,v 1.3 2025/09/12 16:02:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/shape_detection/shape_detection_service.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ services/shape_detection/shape_detection_service.cc
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
