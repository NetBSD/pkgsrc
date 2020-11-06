$NetBSD: patch-Source_WTF_wtf_text_icu_UTextProviderUTF16.cpp,v 1.1 2020/11/06 22:21:35 leot Exp $

Backport upstream changeset 269325.

[WinCairo/PlayStation] ICU 68.1 no longer exposes FALSE and TRUE
macros by default ​https://bugs.webkit.org/show_bug.cgi?id=218522

--- Source/WTF/wtf/text/icu/UTextProviderUTF16.cpp.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/text/icu/UTextProviderUTF16.cpp
@@ -126,7 +126,7 @@ static inline int64_t uTextUTF16ContextA
 static UBool uTextUTF16ContextAwareAccess(UText* text, int64_t nativeIndex, UBool forward)
 {
     if (!text->context)
-        return FALSE;
+        return false;
     int64_t nativeLength = uTextUTF16ContextAwareNativeLength(text);
     UBool isAccessible;
     if (uTextAccessInChunkOrOutOfRange(text, nativeIndex, nativeLength, forward, isAccessible))
@@ -146,7 +146,7 @@ static UBool uTextUTF16ContextAwareAcces
         ASSERT(newContext == UTextProviderContext::PriorContext);
         textUTF16ContextAwareSwitchToPriorContext(text, nativeIndex, nativeLength, forward);
     }
-    return TRUE;
+    return true;
 }
 
 static int32_t uTextUTF16ContextAwareExtract(UText*, int64_t, int64_t, UChar*, int32_t, UErrorCode* errorCode)
