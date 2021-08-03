$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_text_text__break__iterator__icu.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

icu >= 68

--- src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator_icu.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/text/text_break_iterator_icu.cc
@@ -311,13 +311,13 @@ static inline bool TextInChunkOrOutOfRan
       text->chunkOffset = offset <= std::numeric_limits<int32_t>::max()
                               ? static_cast<int32_t>(offset)
                               : 0;
-      is_accessible = TRUE;
+      is_accessible = true;
       return true;
     }
     if (native_index >= native_length &&
         text->chunkNativeLimit == native_length) {
       text->chunkOffset = text->chunkLength;
-      is_accessible = FALSE;
+      is_accessible = false;
       return true;
     }
   } else {
@@ -330,12 +330,12 @@ static inline bool TextInChunkOrOutOfRan
       text->chunkOffset = offset <= std::numeric_limits<int32_t>::max()
                               ? static_cast<int32_t>(offset)
                               : 0;
-      is_accessible = TRUE;
+      is_accessible = true;
       return true;
     }
     if (native_index <= 0 && !text->chunkNativeStart) {
       text->chunkOffset = 0;
-      is_accessible = FALSE;
+      is_accessible = false;
       return true;
     }
   }
@@ -346,7 +346,7 @@ static UBool TextLatin1Access(UText* tex
                               int64_t native_index,
                               UBool forward) {
   if (!text->context)
-    return FALSE;
+    return false;
   int64_t native_length = TextNativeLength(text);
   UBool is_accessible;
   if (TextInChunkOrOutOfRange(text, native_index, native_length, forward,
@@ -370,7 +370,7 @@ static UBool TextLatin1Access(UText* tex
     DCHECK_EQ(new_context, kPriorContext);
     TextLatin1SwitchToPriorContext(text, native_index, native_length, forward);
   }
-  return TRUE;
+  return true;
 }
 
 static const struct UTextFuncs kTextLatin1Funcs = {
@@ -510,7 +510,7 @@ static void TextUTF16SwitchToPriorContex
 
 static UBool TextUTF16Access(UText* text, int64_t native_index, UBool forward) {
   if (!text->context)
-    return FALSE;
+    return false;
   int64_t native_length = TextNativeLength(text);
   UBool is_accessible;
   if (TextInChunkOrOutOfRange(text, native_index, native_length, forward,
@@ -532,7 +532,7 @@ static UBool TextUTF16Access(UText* text
     DCHECK_EQ(new_context, kPriorContext);
     TextUTF16SwitchToPriorContext(text, native_index, native_length, forward);
   }
-  return TRUE;
+  return true;
 }
 
 static const struct UTextFuncs kTextUTF16Funcs = {
