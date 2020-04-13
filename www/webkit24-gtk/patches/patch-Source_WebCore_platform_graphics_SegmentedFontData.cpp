$NetBSD: patch-Source_WebCore_platform_graphics_SegmentedFontData.cpp,v 1.1 2020/04/13 19:11:55 joerg Exp $

--- Source/WebCore/platform/graphics/SegmentedFontData.cpp.orig	2020-04-13 00:58:40.822544476 +0000
+++ Source/WebCore/platform/graphics/SegmentedFontData.cpp
@@ -61,7 +61,7 @@ bool SegmentedFontData::containsCharacte
 {
     UChar32 c;
     for (int i = 0; i < length; ) {
-        U16_NEXT(characters, i, length, c)
+        U16_NEXT(characters, i, length, c);
         if (!containsCharacter(c))
             return false;
     }
