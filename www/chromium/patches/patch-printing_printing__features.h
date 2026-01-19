$NetBSD: patch-printing_printing__features.h,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ printing/printing_features.h
@@ -27,7 +27,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMargins
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX)
 
