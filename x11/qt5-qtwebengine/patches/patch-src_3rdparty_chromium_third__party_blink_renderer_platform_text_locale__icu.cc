$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_text_locale__icu.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

icu >= 68

--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/locale_icu.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/locale_icu.cc
@@ -169,12 +169,12 @@ static String GetDateFormatPattern(const
     return g_empty_string;
 
   UErrorCode status = U_ZERO_ERROR;
-  int32_t length = udat_toPattern(date_format, TRUE, nullptr, 0, &status);
+  int32_t length = udat_toPattern(date_format, true, nullptr, 0, &status);
   if (status != U_BUFFER_OVERFLOW_ERROR || !length)
     return g_empty_string;
   StringBuffer<UChar> buffer(length);
   status = U_ZERO_ERROR;
-  udat_toPattern(date_format, TRUE, buffer.Characters(), length, &status);
+  udat_toPattern(date_format, true, buffer.Characters(), length, &status);
   if (U_FAILURE(status))
     return g_empty_string;
   return String::Adopt(buffer);
