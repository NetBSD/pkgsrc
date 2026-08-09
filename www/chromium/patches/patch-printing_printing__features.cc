$NetBSD: patch-printing_printing__features.cc,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ printing/printing_features.cc
@@ -17,7 +17,7 @@ namespace printing::features {
 BASE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -40,7 +40,7 @@ BASE_FEATURE(kPrintWithReducedRasterizat
 // Enables printing interactions with the operating system to be performed
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
