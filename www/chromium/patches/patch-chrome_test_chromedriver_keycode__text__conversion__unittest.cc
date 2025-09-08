$NetBSD: patch-chrome_test_chromedriver_keycode__text__conversion__unittest.cc,v 1.6 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/keycode_text_conversion_unittest.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/test/chromedriver/keycode_text_conversion_unittest.cc
@@ -64,7 +64,7 @@ std::string ConvertKeyCodeToTextNoError(
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_KeyCodeToText DISABLED_KeyCodeToText
 #else
@@ -98,7 +98,7 @@ TEST(KeycodeTextConversionTest, MAYBE_Ke
       ConvertKeyCodeToTextNoError(ui::VKEY_SHIFT, kShiftKeyModifierMask));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_CharToKeyCode DISABLED_CharToKeyCode
 #else
