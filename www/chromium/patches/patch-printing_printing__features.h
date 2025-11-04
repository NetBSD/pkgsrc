$NetBSD: patch-printing_printing__features.h,v 1.9 2025/11/04 14:55:44 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX)
 
