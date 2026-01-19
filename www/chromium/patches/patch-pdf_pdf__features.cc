$NetBSD: patch-pdf_pdf__features.cc,v 1.1 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdf_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ pdf/pdf_features.cc
@@ -47,7 +47,7 @@ BASE_FEATURE(kPdfUseSkiaRenderer, base::
 // Feature has no effect if Chrome is built with no XFA support.
 BASE_FEATURE(kPdfXfaSupport, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables PDFium's version 2 font mapping interface, which uses per-request
 // font matching instead of enumerating all fonts upfront. This eliminates the
 // need for the ListFamilies() IPC call and improves PDF load performance on
