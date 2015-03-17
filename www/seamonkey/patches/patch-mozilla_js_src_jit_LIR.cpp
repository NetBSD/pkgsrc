$NetBSD: patch-mozilla_js_src_jit_LIR.cpp,v 1.1 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/js/src/jit/LIR.cpp.orig	2015-03-09 05:34:37.000000000 +0000
+++ mozilla/js/src/jit/LIR.cpp
@@ -314,7 +314,7 @@ LNode::printName(FILE *fp, Opcode op)
     const char *name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 void
