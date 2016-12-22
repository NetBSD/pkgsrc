$NetBSD: patch-js_src_jsopcode.cpp,v 1.1 2016/12/22 21:07:58 joerg Exp $

--- js/src/jsopcode.cpp.orig	2015-06-24 21:24:46.000000000 +0000
+++ js/src/jsopcode.cpp
@@ -1609,7 +1609,7 @@ ExpressionDecompiler::write(JSString* st
 bool
 ExpressionDecompiler::quote(JSString* s, uint32_t quote)
 {
-    return QuoteString(&sprinter, s, quote) >= 0;
+    return QuoteString(&sprinter, s, quote);
 }
 
 JSAtom*
