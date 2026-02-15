$NetBSD: patch-chrome_test_chromedriver_keycode__text__conversion__unittest.cc,v 1.15 2026/02/15 09:04:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/test/chromedriver/keycode_text_conversion_unittest.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
