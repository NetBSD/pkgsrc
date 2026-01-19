$NetBSD: patch-pdf_pdf__features.h,v 1.1 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdf_features.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ pdf/pdf_features.h
@@ -31,7 +31,7 @@ BASE_DECLARE_FEATURE(kPdfUseShowSaveFile
 BASE_DECLARE_FEATURE(kPdfUseSkiaRenderer);
 BASE_DECLARE_FEATURE(kPdfXfaSupport);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kPdfiumPerRequestFontMatching);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
