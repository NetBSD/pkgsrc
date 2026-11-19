$NetBSD: patch-printing_backend_cups__helper.h,v 1.29 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_helper.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ printing/backend/cups_helper.h
@@ -32,7 +32,7 @@ constexpr int kCupsTimeoutMs = 3000;
 constexpr cups_ptype_t kDestinationsFilterMask =
     CUPS_PRINTER_FAX | CUPS_PRINTER_SCANNER | CUPS_PRINTER_DISCOVERED;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Helper wrapper around http_t structure, with connection and cleanup
 // functionality.
 class COMPONENT_EXPORT(PRINT_BACKEND) HttpConnectionCUPS {
