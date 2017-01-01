$NetBSD: patch-mozilla_js_src_jit_MIR.cpp,v 1.4 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/js/src/jit/MIR.cpp.orig	2016-12-14 02:09:44.000000000 +0000
+++ mozilla/js/src/jit/MIR.cpp
@@ -76,7 +76,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 static MConstant*
