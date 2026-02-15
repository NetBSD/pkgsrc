$NetBSD: patch-printing_printing__features.h,v 1.15 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMargins
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kLinuxXdgPrintPortal);
 #endif  // BUILDFLAG(IS_LINUX)
