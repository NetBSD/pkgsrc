$NetBSD: patch-js_src_jit_AsmJSModule.cpp,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/jit/AsmJSModule.cpp.orig	2015-04-20 23:47:34.000000000 +0000
+++ js/src/jit/AsmJSModule.cpp
@@ -165,10 +165,10 @@ InvokeFromAsmJS_ToNumber(JSContext *cx, 
 extern "C" {
 
 extern int64_t
-__aeabi_idivmod(int, int);
+__aeabi_idivmod(int, int) MOZ_EXPORT;
 
 extern int64_t
-__aeabi_uidivmod(int, int);
+__aeabi_uidivmod(int, int) MOZ_EXPORT;
 
 }
 #endif
