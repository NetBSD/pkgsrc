$NetBSD: patch-js_src_jit_MIR.cpp,v 1.5 2016/06/16 12:08:21 ryoon Exp $

* For NetBSD

--- js/src/jit/MIR.cpp.orig	2016-05-12 17:05:02.000000000 +0000
+++ js/src/jit/MIR.cpp
@@ -76,7 +76,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 static MConstant*
