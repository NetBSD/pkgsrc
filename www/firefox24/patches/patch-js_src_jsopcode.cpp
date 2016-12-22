$NetBSD: patch-js_src_jsopcode.cpp,v 1.1 2016/12/22 21:07:57 joerg Exp $

--- js/src/jsopcode.cpp.orig	2014-09-24 02:53:36.000000000 +0000
+++ js/src/jsopcode.cpp
@@ -1391,7 +1391,7 @@ ExpressionDecompiler::write(JSString *st
 bool
 ExpressionDecompiler::quote(JSString *s, uint32_t quote)
 {
-    return QuoteString(&sprinter, s, quote) >= 0;
+    return QuoteString(&sprinter, s, quote);
 }
 
 JSAtom *
