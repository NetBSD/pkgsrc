$NetBSD: patch-src_characters_CharacterColor.h,v 1.1 2022/09/29 01:29:05 markd Exp $

error: call to non-constexpr function 'void qt_assert(const char*, const char*, int)'

--- src/characters/CharacterColor.h.orig	2022-08-10 21:32:42.000000000 +0000
+++ src/characters/CharacterColor.h
@@ -247,7 +247,7 @@ constexpr QColor CharacterColor::color(c
         return QColor();
     }
 
-    Q_ASSERT(false); // invalid color space
+    // Q_ASSERT(false); // invalid color space
 
     return QColor();
 }
