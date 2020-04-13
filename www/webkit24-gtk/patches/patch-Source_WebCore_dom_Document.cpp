$NetBSD: patch-Source_WebCore_dom_Document.cpp,v 1.1 2020/04/13 19:11:55 joerg Exp $

--- Source/WebCore/dom/Document.cpp.orig	2020-04-13 01:14:26.456239680 +0000
+++ Source/WebCore/dom/Document.cpp
@@ -3912,12 +3912,12 @@ static bool isValidNameNonASCII(const UC
     unsigned i = 0;
 
     UChar32 c;
-    U16_NEXT(characters, i, length, c)
+    U16_NEXT(characters, i, length, c);
     if (!isValidNameStart(c))
         return false;
 
     while (i < length) {
-        U16_NEXT(characters, i, length, c)
+        U16_NEXT(characters, i, length, c);
         if (!isValidNamePart(c))
             return false;
     }
@@ -3980,7 +3980,7 @@ bool Document::parseQualifiedName(const 
     const UChar* s = qualifiedName.deprecatedCharacters();
     for (unsigned i = 0; i < length;) {
         UChar32 c;
-        U16_NEXT(s, i, length, c)
+        U16_NEXT(s, i, length, c);
         if (c == ':') {
             if (sawColon) {
                 ec = NAMESPACE_ERR;
