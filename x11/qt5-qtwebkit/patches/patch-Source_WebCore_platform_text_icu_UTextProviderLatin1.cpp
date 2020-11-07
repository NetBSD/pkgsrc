$NetBSD: patch-Source_WebCore_platform_text_icu_UTextProviderLatin1.cpp,v 1.1 2020/11/07 09:23:55 wiz Exp $

Compatibility with icu-68.

--- Source/WebCore/platform/text/icu/UTextProviderLatin1.cpp.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/WebCore/platform/text/icu/UTextProviderLatin1.cpp
@@ -100,23 +100,23 @@ static UBool uTextLatin1Access(UText* uT
         if (index < uText->chunkNativeLimit && index >= uText->chunkNativeStart) {
             // Already inside the buffer. Set the new offset.
             uText->chunkOffset = static_cast<int32_t>(index - uText->chunkNativeStart);
-            return TRUE;
+            return true;
         }
         if (index >= length && uText->chunkNativeLimit == length) {
             // Off the end of the buffer, but we can't get it.
             uText->chunkOffset = static_cast<int32_t>(index - uText->chunkNativeStart);
-            return FALSE;
+            return false;
         }
     } else {
         if (index <= uText->chunkNativeLimit && index > uText->chunkNativeStart) {
             // Already inside the buffer. Set the new offset.
             uText->chunkOffset = static_cast<int32_t>(index - uText->chunkNativeStart);
-            return TRUE;
+            return true;
         }
         if (!index && !uText->chunkNativeStart) {
             // Already at the beginning; can't go any farther.
             uText->chunkOffset = 0;
-            return FALSE;
+            return false;
         }
     }
     
@@ -144,7 +144,7 @@ static UBool uTextLatin1Access(UText* uT
 
     uText->nativeIndexingLimit = uText->chunkLength;
 
-    return TRUE;
+    return true;
 }
 
 static int32_t uTextLatin1Extract(UText* uText, int64_t start, int64_t limit, UChar* dest, int32_t destCapacity, UErrorCode* status)
@@ -336,7 +336,7 @@ static int64_t uTextLatin1ContextAwareNa
 static UBool uTextLatin1ContextAwareAccess(UText* text, int64_t nativeIndex, UBool forward)
 {
     if (!text->context)
-        return FALSE;
+        return false;
     int64_t nativeLength = uTextLatin1ContextAwareNativeLength(text);
     UBool isAccessible;
     if (uTextAccessInChunkOrOutOfRange(text, nativeIndex, nativeLength, forward, isAccessible))
@@ -356,7 +356,7 @@ static UBool uTextLatin1ContextAwareAcce
         ASSERT(newContext == UTextProviderContext::PriorContext);
         textLatin1ContextAwareSwitchToPriorContext(text, nativeIndex, nativeLength, forward);
     }
-    return TRUE;
+    return true;
 }
 
 static int32_t uTextLatin1ContextAwareExtract(UText*, int64_t, int64_t, UChar*, int32_t, UErrorCode* errorCode)
