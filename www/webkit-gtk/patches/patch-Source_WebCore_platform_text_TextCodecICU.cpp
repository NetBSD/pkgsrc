$NetBSD: patch-Source_WebCore_platform_text_TextCodecICU.cpp,v 1.1 2020/11/06 22:21:35 leot Exp $

Backport upstream changeset 269325.

[WinCairo/PlayStation] ICU 68.1 no longer exposes FALSE and TRUE
macros by default ​https://bugs.webkit.org/show_bug.cgi?id=218522

--- Source/WebCore/platform/text/TextCodecICU.cpp.orig	2020-08-12 09:17:55.000000000 +0000
+++ Source/WebCore/platform/text/TextCodecICU.cpp
@@ -240,7 +240,7 @@ void TextCodecICU::createICUConverter() 
     UErrorCode error = U_ZERO_ERROR;
     m_converter = ICUConverterPtr { ucnv_open(m_canonicalConverterName, &error), ucnv_close };
     if (m_converter)
-        ucnv_setFallback(m_converter.get(), TRUE);
+        ucnv_setFallback(m_converter.get(), true);
 }
 
 int TextCodecICU::decodeToBuffer(UChar* target, UChar* targetLimit, const char*& source, const char* sourceLimit, int32_t* offsets, bool flush, UErrorCode& error)
