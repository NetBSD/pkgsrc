$NetBSD: patch-src_lexer.c,v 1.1 2015/07/26 15:58:53 spz Exp $

Fix for CVE-2015-5522 and CVE-2015-5523 from
https://github.com/htacg/tidy-html5/commit/c18f27a58792f7fbd0b30a0ff50d6b40a82f940d

--- src/lexer.c.orig	2008-03-22 21:06:55.000000000 +0000
+++ src/lexer.c
@@ -3467,16 +3467,16 @@ static tmbstr ParseValue( TidyDocImpl* d
         /* and prompts attributes unless --literal-attributes is set to yes      */
         /* #994841 - Whitespace is removed from value attributes                 */
 
-        if (munge &&
+        if ((len > 0) && munge &&
             TY_(tmbstrcasecmp)(name, "alt") &&
             TY_(tmbstrcasecmp)(name, "title") &&
             TY_(tmbstrcasecmp)(name, "value") &&
             TY_(tmbstrcasecmp)(name, "prompt"))
         {
-            while (TY_(IsWhite)(lexer->lexbuf[start+len-1]))
+            while (TY_(IsWhite)(lexer->lexbuf[start+len-1]) && (len > 0))
                 --len;
 
-            while (TY_(IsWhite)(lexer->lexbuf[start]) && start < len)
+            while (TY_(IsWhite)(lexer->lexbuf[start]) && (start < len) && (len > 0))
             {
                 ++start;
                 --len;
