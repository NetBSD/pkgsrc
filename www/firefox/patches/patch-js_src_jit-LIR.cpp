$NetBSD: patch-js_src_jit-LIR.cpp,v 1.1 2015/02/16 16:16:17 bad Exp $

--- js/src/jit/LIR.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jit/LIR.cpp	2015-02-05 12:03:55.000000000 +0000
@@ -314,7 +314,7 @@
     const char *name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 void
