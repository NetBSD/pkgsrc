$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.3 2012/04/28 22:48:06 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2012-04-23 06:27:43.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -167,7 +167,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
