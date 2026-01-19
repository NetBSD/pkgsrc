$NetBSD: patch-printing_printing__features.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ printing/printing_features.cc
@@ -26,7 +26,7 @@ BASE_FEATURE(kApiPrintingMarginsAndScale
 BASE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -58,7 +58,7 @@ BASE_FEATURE(kUseXpsForPrintingFromPdf, 
 // Enables printing interactions with the operating system to be performed
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
