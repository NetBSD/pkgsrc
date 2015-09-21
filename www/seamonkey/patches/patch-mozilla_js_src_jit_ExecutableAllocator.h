$NetBSD: patch-mozilla_js_src_jit_ExecutableAllocator.h,v 1.3 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/js/src/jit/ExecutableAllocator.h.orig	2015-09-02 09:27:29.000000000 +0000
+++ mozilla/js/src/jit/ExecutableAllocator.h
@@ -419,6 +419,11 @@ class ExecutableAllocator {
     {
         __clear_cache(code, reinterpret_cast<char*>(code) + size);
     }
+#elif defined(JS_CODEGEN_ARM) && (defined(__FreeBSD__) || defined(__NetBSD__))
+    static void cacheFlush(void* code, size_t size)
+    {
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID)) && defined(__GNUC__)
     static void cacheFlush(void* code, size_t size)
     {
