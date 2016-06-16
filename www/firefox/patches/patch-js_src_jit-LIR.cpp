$NetBSD: patch-js_src_jit-LIR.cpp,v 1.4 2016/06/16 12:08:21 ryoon Exp $

* For NetBSD

--- js/src/jit/LIR.cpp.orig	2015-08-24 21:53:12.000000000 +0000
+++ js/src/jit/LIR.cpp
@@ -323,7 +323,7 @@ LNode::printName(GenericPrinter& out, Op
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 void
