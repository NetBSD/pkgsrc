$NetBSD: patch-src_3rdparty_chromium_printing_backend_cups__helper.h,v 1.1 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/printing/backend/cups_helper.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/printing/backend/cups_helper.h
@@ -32,7 +32,7 @@ constexpr int kCupsTimeoutMs = 3000;
 constexpr cups_ptype_t kDestinationsFilterMask =
     CUPS_PRINTER_FAX | CUPS_PRINTER_SCANNER | CUPS_PRINTER_DISCOVERED;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Helper wrapper around http_t structure, with connection and cleanup
 // functionality.
 class COMPONENT_EXPORT(PRINT_BACKEND) HttpConnectionCUPS {
