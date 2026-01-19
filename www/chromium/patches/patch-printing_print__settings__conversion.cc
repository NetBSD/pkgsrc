$NetBSD: patch-printing_print__settings__conversion.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/print_settings_conversion.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ printing/print_settings_conversion.cc
@@ -291,7 +291,7 @@ std::unique_ptr<PrintSettings> PrintSett
     settings->set_is_modifiable(is_modifiable.value());
   }
 
-#if BUILDFLAG(IS_CHROMEOS) || (BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS))
+#if BUILDFLAG(IS_CHROMEOS) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_CUPS))
   const base::Value::Dict* advanced_settings =
       job_settings.FindDict(kSettingAdvancedSettings);
   if (advanced_settings) {
