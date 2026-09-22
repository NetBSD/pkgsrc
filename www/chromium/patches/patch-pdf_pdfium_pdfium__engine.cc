$NetBSD: patch-pdf_pdfium_pdfium__engine.cc,v 1.26 2026/09/22 13:41:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdfium/pdfium_engine.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ pdf/pdfium/pdfium_engine.cc
@@ -133,7 +133,7 @@
 #include "ui/accessibility/ax_features.mojom-features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "pdf/pdfium/pdfium_font_linux.h"
 #endif
 
@@ -841,7 +841,7 @@ void InitializeSDK(bool enable_v8,
 
   FPDF_InitLibraryWithConfig(&config);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   g_font_mapping_mode = font_mapping_mode;
   InitializeLinuxFontMapper();
 #endif
