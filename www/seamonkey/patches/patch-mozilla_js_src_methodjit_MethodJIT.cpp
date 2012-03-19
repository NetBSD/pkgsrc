$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.2 2012/03/19 10:36:00 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2012-03-13 05:32:43.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -170,7 +170,7 @@ SetVMFrameRegs(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
