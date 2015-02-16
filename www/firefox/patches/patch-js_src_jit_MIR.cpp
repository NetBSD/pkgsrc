$NetBSD: patch-js_src_jit_MIR.cpp,v 1.1 2015/02/16 16:16:17 bad Exp $

--- js/src/jit/MIR.cpp.orig	2015-01-23 06:00:01.000000000 +0000
+++ js/src/jit/MIR.cpp	2015-02-05 12:06:56.000000000 +0000
@@ -68,7 +68,7 @@
     const char *name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 static MConstant *
