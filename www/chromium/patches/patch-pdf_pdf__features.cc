$NetBSD: patch-pdf_pdf__features.cc,v 1.2 2026/02/15 09:04:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- pdf/pdf_features.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ pdf/pdf_features.cc
@@ -54,7 +54,7 @@ const base::FeatureParam<bool> kPdfUseSk
 // Feature has no effect if Chrome is built with no XFA support.
 BASE_FEATURE(kPdfXfaSupport, base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables PDFium's version 2 font mapping interface, which uses per-request
 // font matching instead of enumerating all fonts upfront. This eliminates the
 // need for the ListFamilies() IPC call and improves PDF load performance on
