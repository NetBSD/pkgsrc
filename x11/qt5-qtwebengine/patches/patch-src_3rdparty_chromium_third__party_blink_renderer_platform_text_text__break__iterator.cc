$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_text_text__break__iterator.cc,v 1.3 2026/01/03 03:38:56 ryoon Exp $

* SUpport ICU 78.1.

--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2026-01-03 02:14:17.110113138 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -162,7 +162,9 @@ static const unsigned char kAsciiLineBreakTable[][(kAs
 };
 // clang-format on
 
-#if U_ICU_VERSION_MAJOR_NUM >= 74
+#if U_ICU_VERSION_MAJOR_NUM >= 78
+#define BA_LB_COUNT (U_LB_COUNT - 9)
+#elif U_ICU_VERSION_MAJOR_NUM >= 74
 #define BA_LB_COUNT (U_LB_COUNT - 8)
 #elif U_ICU_VERSION_MAJOR_NUM >= 58
 #define BA_LB_COUNT (U_LB_COUNT - 3)
