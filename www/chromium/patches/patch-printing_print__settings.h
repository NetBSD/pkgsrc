$NetBSD: patch-printing_print__settings.h,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/print_settings.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ printing/print_settings.h
@@ -25,7 +25,7 @@
 #include "base/values.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <map>
 
 #include "base/values.h"
@@ -52,7 +52,7 @@ inline constexpr char kMacSystemPrintDia
     "print_settings";
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kLinuxSystemPrintDialogDataPrinter[] = "printer_name";
 inline constexpr char kLinuxSystemPrintDialogDataPrintSettings[] =
     "print_settings";
@@ -102,7 +102,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
     std::string vendor_id;
   };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   using AdvancedSettings = std::map<std::string, base::Value>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -290,7 +290,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
     pages_per_sheet_ = pages_per_sheet;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   AdvancedSettings& advanced_settings() { return advanced_settings_; }
   const AdvancedSettings& advanced_settings() const {
     return advanced_settings_;
@@ -451,7 +451,7 @@ class COMPONENT_EXPORT(PRINTING_SETTINGS
   // Number of pages per sheet.
   int pages_per_sheet_;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Advanced settings.
   AdvancedSettings advanced_settings_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
