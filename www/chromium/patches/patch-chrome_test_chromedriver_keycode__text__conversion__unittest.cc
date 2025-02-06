$NetBSD: patch-chrome_test_chromedriver_keycode__text__conversion__unittest.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/keycode_text_conversion_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/test/chromedriver/keycode_text_conversion_unittest.cc
@@ -67,7 +67,7 @@ std::string ConvertKeyCodeToTextNoError(
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_KeyCodeToText DISABLED_KeyCodeToText
 #else
@@ -104,7 +104,7 @@ TEST(KeycodeTextConversionTest, MAYBE_Ke
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_CharToKeyCode DISABLED_CharToKeyCode
 #else
