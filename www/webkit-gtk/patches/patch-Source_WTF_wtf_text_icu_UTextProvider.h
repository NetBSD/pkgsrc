$NetBSD: patch-Source_WTF_wtf_text_icu_UTextProvider.h,v 1.1 2020/11/06 22:21:35 leot Exp $

Backport upstream changeset 269325.

[WinCairo/PlayStation] ICU 68.1 no longer exposes FALSE and TRUE
macros by default ​https://bugs.webkit.org/show_bug.cgi?id=218522

--- Source/WTF/wtf/text/icu/UTextProvider.h.orig	2020-08-12 09:17:54.000000000 +0000
+++ Source/WTF/wtf/text/icu/UTextProvider.h
@@ -79,12 +79,12 @@ inline bool uTextAccessInChunkOrOutOfRan
             // Ensure chunk offset is well formed if computed offset exceeds int32_t range.
             ASSERT(offset < std::numeric_limits<int32_t>::max());
             text->chunkOffset = offset < std::numeric_limits<int32_t>::max() ? static_cast<int32_t>(offset) : 0;
-            isAccessible = TRUE;
+            isAccessible = true;
             return true;
         }
         if (nativeIndex >= nativeLength && text->chunkNativeLimit == nativeLength) {
             text->chunkOffset = text->chunkLength;
-            isAccessible = FALSE;
+            isAccessible = false;
             return true;
         }
     } else {
@@ -93,12 +93,12 @@ inline bool uTextAccessInChunkOrOutOfRan
             // Ensure chunk offset is well formed if computed offset exceeds int32_t range.
             ASSERT(offset < std::numeric_limits<int32_t>::max());
             text->chunkOffset = offset < std::numeric_limits<int32_t>::max() ? static_cast<int32_t>(offset) : 0;
-            isAccessible = TRUE;
+            isAccessible = true;
             return true;
         }
         if (nativeIndex <= 0 && !text->chunkNativeStart) {
             text->chunkOffset = 0;
-            isAccessible = FALSE;
+            isAccessible = false;
             return true;
         }
     }
