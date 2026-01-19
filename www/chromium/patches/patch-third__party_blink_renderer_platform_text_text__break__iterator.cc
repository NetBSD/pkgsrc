$NetBSD: patch-third__party_blink_renderer_platform_text_text__break__iterator.cc,v 1.4 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/text/text_break_iterator.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/platform/text/text_break_iterator.cc
@@ -102,6 +102,10 @@ static const unsigned char kBreakAllLine
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // VF
     { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // VI
 #endif  // U_ICU_VERSION_MAJOR_NUM >= 74
+#if U_ICU_VERSION_MAJOR_NUM >= 78
+    // Added in ICU 78. https://icu.unicode.org/download/78
+    { B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0, 0, 0), B(0, 0,  0, 0, 0, 0, 0, 0) }, // UH
+#endif  // U_ICU_VERSION_MAJOR_NUM >= 78
 };
 // clang-format on
 
