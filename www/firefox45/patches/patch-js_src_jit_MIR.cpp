$NetBSD: patch-js_src_jit_MIR.cpp,v 1.1 2016/04/27 16:36:50 ryoon Exp $

--- js/src/jit/MIR.cpp.orig	2015-08-24 21:53:12.000000000 +0000
+++ js/src/jit/MIR.cpp
@@ -72,7 +72,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 const Value&
