$NetBSD: patch-mozilla_js_src_jit_ExecutableAllocator.h,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/js/src/jit/ExecutableAllocator.h.orig	2014-12-03 06:22:56.000000000 +0000
+++ mozilla/js/src/jit/ExecutableAllocator.h
@@ -428,7 +428,7 @@ public:
 
 #undef GCC_VERSION
     }
-#elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID)) && defined(__GNUC__)
+#elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)) && defined(__GNUC__)
     static void cacheFlush(void* code, size_t size)
     {
         asm volatile (
