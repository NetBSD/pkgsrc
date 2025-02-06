$NetBSD: patch-printing_backend_print__backend__cups.cc,v 1.1 2025/02/06 09:58:16 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/backend/print_backend_cups.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ printing/backend/print_backend_cups.cc
@@ -33,7 +33,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/feature_list.h"
 #include "printing/backend/cups_connection.h"
 #include "printing/backend/print_backend_cups_ipp.h"
@@ -63,7 +63,7 @@ int CaptureCupsDestCallback(void* data, 
   return 1;  // Keep going.
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 // This may be removed when Amazon Linux 2 reaches EOL (30 Jun 2025).
 bool AreNewerCupsFunctionsAvailable() {
   return cupsFindDestDefault && cupsFindDestSupported && cupsUserAgent &&
@@ -292,7 +292,7 @@ bool PrintBackendCUPS::IsValidPrinter(co
 #if !BUILDFLAG(IS_CHROMEOS)
 scoped_refptr<PrintBackend> PrintBackend::CreateInstanceImpl(
     const std::string& locale) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (AreNewerCupsFunctionsAvailable() &&
       base::FeatureList::IsEnabled(features::kCupsIppPrintingBackend)) {
     return base::MakeRefCounted<PrintBackendCupsIpp>(CupsConnection::Create());
