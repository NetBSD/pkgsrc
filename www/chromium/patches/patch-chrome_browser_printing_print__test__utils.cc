$NetBSD: patch-chrome_browser_printing_print__test__utils.cc,v 1.15 2026/10/13 13:16:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/printing/print_test_utils.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/printing/print_test_utils.cc
@@ -138,7 +138,7 @@ std::unique_ptr<PrintSettings> MakeUserM
     data.Set(kMacSystemPrintDialogDataPrintSettings,
              base::Value::BlobStorage({0xB2}));
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     data.Set(kLinuxSystemPrintDialogDataPrinter, printer_name);
     data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings");
     data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup");
