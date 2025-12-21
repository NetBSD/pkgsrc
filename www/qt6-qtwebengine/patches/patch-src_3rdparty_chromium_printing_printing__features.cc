$NetBSD: patch-src_3rdparty_chromium_printing_printing__features.cc,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/printing/printing_features.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/printing/printing_features.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kAddPrinterViaPrintscanmgr,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend,
@@ -69,7 +69,7 @@ BASE_FEATURE(kUseXpsForPrintingFromPdf,
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
              "EnableOopPrintDrivers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
