$NetBSD: patch-Source_WebCore_platform_text_TextCodecICU.cpp,v 1.1 2020/11/07 09:23:55 wiz Exp $

Compatibility with icu-68.

--- Source/WebCore/platform/text/TextCodecICU.cpp.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/WebCore/platform/text/TextCodecICU.cpp
@@ -308,7 +308,7 @@ void TextCodecICU::createICUConverter() 
     m_converterICU = ucnv_open(m_canonicalConverterName, &err);
     ASSERT(U_SUCCESS(err));
     if (m_converterICU)
-        ucnv_setFallback(m_converterICU, TRUE);
+        ucnv_setFallback(m_converterICU, true);
 }
 
 int TextCodecICU::decodeToBuffer(UChar* target, UChar* targetLimit, const char*& source, const char* sourceLimit, int32_t* offsets, bool flush, UErrorCode& err)
