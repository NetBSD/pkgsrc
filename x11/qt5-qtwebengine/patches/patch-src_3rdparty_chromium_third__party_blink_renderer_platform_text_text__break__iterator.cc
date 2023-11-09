$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_text_text__break__iterator.cc,v 1.1 2023/11/09 07:37:47 wiz Exp $

Fix build with icu 74.1.

--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2022-09-19 14:36:40.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -162,7 +162,9 @@ static const unsigned char kAsciiLineBre
 };
 // clang-format on
 
-#if U_ICU_VERSION_MAJOR_NUM >= 58
+#if U_ICU_VERSION_MAJOR_NUM >= 74
+#define BA_LB_COUNT 40
+#elif U_ICU_VERSION_MAJOR_NUM >= 58
 #define BA_LB_COUNT (U_LB_COUNT - 3)
 #else
 #define BA_LB_COUNT U_LB_COUNT
