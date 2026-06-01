$NetBSD: patch-printing_printing__features.h,v 1.20 2026/06/01 10:09:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMargins
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kLinuxXdgPrintPortal);
 #endif  // BUILDFLAG(IS_LINUX)
