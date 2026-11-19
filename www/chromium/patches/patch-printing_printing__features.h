$NetBSD: patch-printing_printing__features.h,v 1.33 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ printing/printing_features.h
@@ -19,7 +19,7 @@ namespace printing::features {
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kLinuxXdgPrintPortal);
 #endif  // BUILDFLAG(IS_LINUX)
