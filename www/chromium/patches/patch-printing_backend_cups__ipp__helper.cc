$NetBSD: patch-printing_backend_cups__ipp__helper.cc,v 1.25 2026/09/02 13:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_ipp_helper.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ printing/backend/cups_ipp_helper.cc
@@ -199,7 +199,7 @@ void ExtractResolutions(const CupsOption
   // Provide a default DPI if no valid DPI is found.
 #if BUILDFLAG(IS_MAC)
   constexpr gfx::Size kDefaultMissingDpi(kDefaultMacDpi, kDefaultMacDpi);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   constexpr gfx::Size kDefaultMissingDpi(kPixelsPerInch, kPixelsPerInch);
 #else
   constexpr gfx::Size kDefaultMissingDpi(kDefaultPdfDpi, kDefaultPdfDpi);
