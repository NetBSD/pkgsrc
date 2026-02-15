$NetBSD: patch-pdf_pdf__features.h,v 1.2 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdf_features.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ pdf/pdf_features.h
@@ -32,7 +32,7 @@ BASE_DECLARE_FEATURE(kPdfUseSkiaRenderer
 extern const base::FeatureParam<bool> kPdfUseSkiaPremultiplied;
 BASE_DECLARE_FEATURE(kPdfXfaSupport);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kPdfiumPerRequestFontMatching);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
