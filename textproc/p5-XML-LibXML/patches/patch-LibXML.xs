$NetBSD: patch-LibXML.xs,v 1.1 2026/05/11 17:39:13 wiz Exp $

fix: validate UTF-8 continuation bytes in domParseChar
https://github.com/cpan-authors/XML-LibXML/pull/149

--- LibXML.xs.orig	2023-11-29 06:05:01.000000000 +0000
+++ LibXML.xs
@@ -1001,24 +1001,28 @@ LibXML_test_node_name( xmlChar * name )
     xmlChar * cur = name;
     int tc  = 0;
     int len = 0;
+    int remaining;
 
     if ( cur == NULL || *cur == 0 ) {
         /* warn("name is empty" ); */
         return(0);
     }
 
-    tc = domParseChar( cur, &len );
+    remaining = xmlStrlen(name);
 
+    tc = domParseChar( cur, &len, remaining );
+
     if ( !( IS_LETTER( tc ) || (tc == '_') || (tc == ':')) ) {
         /* warn( "is not a letter\n" ); */
         return(0);
     }
 
     tc  =  0;
+    remaining -= len;
     cur += len;
 
     while (*cur != 0 ) {
-        tc = domParseChar( cur, &len );
+        tc = domParseChar( cur, &len, remaining );
 
         if (!(IS_LETTER(tc) || IS_DIGIT(tc) || (tc == '_') ||
              (tc == '-') || (tc == ':') || (tc == '.') ||
@@ -1027,6 +1031,7 @@ LibXML_test_node_name( xmlChar * name )
             return(0);
         }
         tc = 0;
+        remaining -= len;
         cur += len;
     }
 
