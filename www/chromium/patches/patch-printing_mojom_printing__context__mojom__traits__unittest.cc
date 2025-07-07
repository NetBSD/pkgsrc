$NetBSD: patch-printing_mojom_printing__context__mojom__traits__unittest.cc,v 1.2 2025/07/07 09:23:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- printing/mojom/printing_context_mojom_traits_unittest.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ printing/mojom/printing_context_mojom_traits_unittest.cc
@@ -79,7 +79,7 @@ base::Value::Dict GenerateSampleSystemPr
     data.Set(kMacSystemPrintDialogDataDestinationLocation, "/foo/bar.pdf");
   }
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   data.Set(kLinuxSystemPrintDialogDataPrinter, "printer-name");
   data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings-foo");
   data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup-bar");
@@ -116,7 +116,7 @@ const PageMargins kPrintSettingsCustomMa
                                                        /*top=*/10583,
                                                        /*bottom=*/12347);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 PrintSettings::AdvancedSettings GenerateSampleAdvancedSettings() {
   PrintSettings::AdvancedSettings advanced_settings;
   advanced_settings.emplace("advanced-setting-A", base::Value("setting-A"));
@@ -209,7 +209,7 @@ PrintSettings GenerateSamplePrintSetting
   settings.set_device_name(kPrintSettingsDeviceName);
   settings.set_requested_media(kPrintSettingsRequestedMedia);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   PrintSettings::AdvancedSettings& advanced_settings =
       settings.advanced_settings();
   for (const auto& item : kPrintSettingsAdvancedSettings)
@@ -547,7 +547,7 @@ TEST(PrintingContextMojomTraitsTest,
 
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet1);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -600,7 +600,7 @@ TEST(PrintingContextMojomTraitsTest,
                                kPrintSettingsCustomMarginsInMicrons));
   EXPECT_EQ(output.pages_per_sheet(), kPrintSettingsPagesPerSheet2);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   EXPECT_EQ(output.advanced_settings(), kPrintSettingsAdvancedSettings);
 #endif
 
@@ -639,7 +639,7 @@ TEST(PrintingContextMojomTraitsTest,
   EXPECT_EQ(output.page_setup_device_units(), kInput.page_setup_device_units());
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 TEST(PrintingContextMojomTraitsTest,
      TestSerializeAndDeserializePrintSettingsEmptyAdvancedSettings) {
   PrintSettings input = GenerateSamplePrintSettingsDefaultMargins();
@@ -837,7 +837,7 @@ TEST(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 TEST(
     PrintingContextMojomTraitsTest,
     TestSerializeAndDeserializePrintSettingsSystemPrintDialogPrinterInvalidDataType) {
