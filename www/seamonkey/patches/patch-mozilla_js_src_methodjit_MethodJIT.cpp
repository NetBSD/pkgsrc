$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.7 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2013-05-03 03:07:59.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -138,7 +138,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
@@ -152,7 +152,7 @@ JS_STATIC_ASSERT(offsetof(FrameRegs, sp)
 
 #if defined(XP_MACOSX)
 # define HIDE_SYMBOL(name) ".private_extern _" #name
-#elif defined(__linux__)
+#elif defined(__ELF__)
 # define HIDE_SYMBOL(name) ".hidden" #name
 #else
 # define HIDE_SYMBOL(name)
