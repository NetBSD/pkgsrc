$NetBSD: patch-js_src_jit_ExecutableAllocator.h,v 1.5 2017/08/15 01:24:47 ryoon Exp $

* Support bigendian architectures

--- js/src/jit/ExecutableAllocator.h.orig	2017-06-15 20:52:05.000000000 +0000
+++ js/src/jit/ExecutableAllocator.h
@@ -219,7 +219,7 @@ class ExecutableAllocator
 
     static void poisonCode(JSRuntime* rt, JitPoisonRangeVector& ranges);
 
-#if defined(JS_CODEGEN_X86) || defined(JS_CODEGEN_X64) || defined(JS_SIMULATOR_ARM64)
+#if defined(JS_CODEGEN_X86) || defined(JS_CODEGEN_X64) || defined(JS_SIMULATOR_ARM64) || defined(JS_CODEGEN_NONE)
     static void cacheFlush(void*, size_t)
     {
     }
