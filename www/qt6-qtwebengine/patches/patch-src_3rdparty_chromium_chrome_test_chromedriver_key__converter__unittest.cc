$NetBSD: patch-src_3rdparty_chromium_chrome_test_chromedriver_key__converter__unittest.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/test/chromedriver/key_converter_unittest.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/test/chromedriver/key_converter_unittest.cc
@@ -252,7 +252,7 @@ TEST(KeyConverter, ToggleModifiers) {
   CheckEventsReleaseModifiers(keys, key_events);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_AllEnglishKeyboardSymbols DISABLED_AllEnglishKeyboardSymbols
 #else
@@ -310,7 +310,7 @@ TEST(KeyConverter, AllEnglishKeyboardTex
 TEST(KeyConverter, AllSpecialWebDriverKeysOnEnglishKeyboard) {
   ui::ScopedKeyboardLayout keyboard_layout(ui::KEYBOARD_LAYOUT_ENGLISH_US);
   const auto kTextForKeys = std::to_array<char>({
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       0,   0,   0,   0,   '\t', 0,   '\r', '\r', 0,   0,   0,   0,   0,
 #else
       0,   0,   0,   0,   0,   0,   '\r', '\r', 0,   0,   0,   0,   0,
