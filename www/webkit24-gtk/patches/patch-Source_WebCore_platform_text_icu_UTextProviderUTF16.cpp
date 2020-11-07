$NetBSD: patch-Source_WebCore_platform_text_icu_UTextProviderUTF16.cpp,v 1.1 2020/11/07 02:59:45 ryoon Exp $

--- Source/WebCore/platform/text/icu/UTextProviderUTF16.cpp.orig	2015-07-22 12:37:57.000000000 +0000
+++ Source/WebCore/platform/text/icu/UTextProviderUTF16.cpp
@@ -125,7 +125,7 @@ static inline int64_t uTextUTF16ContextA
 static UBool uTextUTF16ContextAwareAccess(UText* text, int64_t nativeIndex, UBool forward)
 {
     if (!text->context)
-        return FALSE;
+        return false;
     int64_t nativeLength = uTextUTF16ContextAwareNativeLength(text);
     UBool isAccessible;
     if (uTextAccessInChunkOrOutOfRange(text, nativeIndex, nativeLength, forward, isAccessible))
@@ -145,7 +145,7 @@ static UBool uTextUTF16ContextAwareAcces
         ASSERT(newContext == UTextProviderContext::PriorContext);
         textUTF16ContextAwareSwitchToPriorContext(text, nativeIndex, nativeLength, forward);
     }
-    return TRUE;
+    return true;
 }
 
 static int32_t uTextUTF16ContextAwareExtract(UText*, int64_t, int64_t, UChar*, int32_t, UErrorCode* errorCode)
