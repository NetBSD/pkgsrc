$NetBSD: patch-js_src_assembler_jit_ExecutableAllocator.h,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- js/src/assembler/jit/ExecutableAllocator.h.orig	2015-04-10 13:30:05.000000000 +0000
+++ js/src/assembler/jit/ExecutableAllocator.h
@@ -471,6 +471,12 @@ public:
             : "r" (code), "r" (reinterpret_cast<char*>(code) + size)
             : "r0", "r1", "r2");
     }
+#elif WTF_CPU_ARM && defined(__NetBSD__)
+    static void cacheFlush(void* code, size_t size)
+    {
+        intptr_t end = reinterpret_cast<intptr_t>(code) + size;
+        __builtin___clear_cache(reinterpret_cast<char*>(code), reinterpret_cast<char*>(end));
+    }
 #elif WTF_OS_SYMBIAN
     static void cacheFlush(void* code, size_t size)
     {
