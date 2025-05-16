$NetBSD: patch-printing_backend_cups__ipp__helper.cc,v 1.2 2025/05/16 16:08:28 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/cups_ipp_helper.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ printing/backend/cups_ipp_helper.cc
@@ -201,7 +201,7 @@ void ExtractResolutions(const CupsOption
   // Provide a default DPI if no valid DPI is found.
 #if BUILDFLAG(IS_MAC)
   constexpr gfx::Size kDefaultMissingDpi(kDefaultMacDpi, kDefaultMacDpi);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   constexpr gfx::Size kDefaultMissingDpi(kPixelsPerInch, kPixelsPerInch);
 #else
   constexpr gfx::Size kDefaultMissingDpi(kDefaultPdfDpi, kDefaultPdfDpi);
