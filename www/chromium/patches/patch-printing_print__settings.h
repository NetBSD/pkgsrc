$NetBSD: patch-printing_print__settings.h,v 1.1 2025/02/06 09:58:16 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/print_settings.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ printing/print_settings.h
@@ -25,7 +25,7 @@
 #include "base/values.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -51,7 +51,7 @@ inline constexpr char kMacSystemPrintDia
     "print_settings";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kLinuxSystemPrintDialogDataPrinter[] = "printer_name";
 inline constexpr char kLinuxSystemPrintDialogDataPrintSettings[] =
     "print_settings";
@@ -101,7 +101,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
     std::string vendor_id;
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -276,7 +276,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -429,7 +429,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
