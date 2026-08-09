$NetBSD: patch-pdf_pdfium_pdfium__engine.cc,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdfium/pdfium_engine.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ pdf/pdfium/pdfium_engine.cc
@@ -132,7 +132,7 @@
 #include "ui/accessibility/ax_features.mojom-features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -786,7 +786,7 @@ void InitializeSDK(bool enable_v8,
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   g_font_mapping_mode = font_mapping_mode;
   InitializeLinuxFontMapper();
 #endif
