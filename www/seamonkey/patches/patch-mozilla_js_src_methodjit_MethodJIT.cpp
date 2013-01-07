$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.6 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2012-11-18 10:19:40.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -135,7 +135,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
