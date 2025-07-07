$NetBSD: patch-printing_printing__features.h,v 1.3 2025/07/07 09:23:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/printing_features.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ printing/printing_features.h
@@ -24,7 +24,7 @@ COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
 
