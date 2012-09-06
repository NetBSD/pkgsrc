$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.4 2012/09/06 12:08:52 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2012-08-27 04:49:16.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -135,7 +135,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
