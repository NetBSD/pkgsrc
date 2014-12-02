$NetBSD: patch-js_src_jit_ExecutableAllocator.h,v 1.1 2014/12/02 21:27:18 ryoon Exp $

--- js/src/jit/ExecutableAllocator.h.orig	2014-11-26 12:30:07.000000000 +0000
+++ js/src/jit/ExecutableAllocator.h
@@ -428,7 +428,7 @@ public:
 
 #undef GCC_VERSION
     }
-#elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID)) && defined(__GNUC__)
+#elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)) && defined(__GNUC__)
     static void cacheFlush(void* code, size_t size)
     {
         asm volatile (
