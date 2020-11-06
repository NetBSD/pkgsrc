$NetBSD: patch-Source_WTF_wtf_text_icu_UTextProviderLatin1.cpp,v 1.1 2020/11/06 22:21:35 leot Exp $

Backport upstream changeset 269325.

[WinCairo/PlayStation] ICU 68.1 no longer exposes FALSE and TRUE
macros by default ​https://bugs.webkit.org/show_bug.cgi?id=218522

--- Source/WTF/wtf/text/icu/UTextProviderLatin1.cpp.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/text/icu/UTextProviderLatin1.cpp
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
@@ -337,7 +337,7 @@ static int64_t uTextLatin1ContextAwareNa
 static UBool uTextLatin1ContextAwareAccess(UText* text, int64_t nativeIndex, UBool forward)
 {
     if (!text->context)
-        return FALSE;
+        return false;
     int64_t nativeLength = uTextLatin1ContextAwareNativeLength(text);
     UBool isAccessible;
     if (uTextAccessInChunkOrOutOfRange(text, nativeIndex, nativeLength, forward, isAccessible))
@@ -357,7 +357,7 @@ static UBool uTextLatin1ContextAwareAcce
         ASSERT(newContext == UTextProviderContext::PriorContext);
         textLatin1ContextAwareSwitchToPriorContext(text, nativeIndex, nativeLength, forward);
     }
-    return TRUE;
+    return true;
 }
 
 static int32_t uTextLatin1ContextAwareExtract(UText*, int64_t, int64_t, UChar*, int32_t, UErrorCode* errorCode)
