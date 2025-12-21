$NetBSD: patch-src_3rdparty_chromium_printing_printing__features.h,v 1.1 2025/12/21 09:38:35 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/printing/printing_features.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/printing/printing_features.h
@@ -22,7 +22,7 @@ COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAddPrinterViaPrintscanmgr);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
