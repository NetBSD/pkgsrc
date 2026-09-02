$NetBSD: patch-chrome_browser_printing_print__test__utils.cc,v 1.11 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/printing/print_test_utils.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/printing/print_test_utils.cc
@@ -138,7 +138,7 @@ std::unique_ptr<PrintSettings> MakeUserM
     data.Set(kMacSystemPrintDialogDataPrintSettings,
              base::Value::BlobStorage({0xB2}));
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     data.Set(kLinuxSystemPrintDialogDataPrinter, printer_name);
     data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings");
     data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup");
