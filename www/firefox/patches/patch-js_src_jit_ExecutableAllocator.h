$NetBSD: patch-js_src_jit_ExecutableAllocator.h,v 1.2 2015/02/28 04:30:55 ryoon Exp $

--- js/src/jit/ExecutableAllocator.h.orig	2015-02-17 21:40:41.000000000 +0000
+++ js/src/jit/ExecutableAllocator.h
@@ -425,6 +425,11 @@ public:
 
 #undef GCC_VERSION
     }
+#elif defined(JS_CODEGEN_ARM) && (defined(__FreeBSD__) || defined(__NetBSD__))
+    static void cacheFlush(void* code, size_t size)
+    {
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID)) && defined(__GNUC__)
     static void cacheFlush(void* code, size_t size)
     {
