$NetBSD: patch-js_src_assembler_jit_ExecutableAllocator.h,v 1.1 2014/11/26 14:56:28 ryoon Exp $

* Define cacheFlush for NetBSD.

--- js/src/assembler/jit/ExecutableAllocator.h.orig	2014-11-13 22:50:00.000000000 +0000
+++ js/src/assembler/jit/ExecutableAllocator.h
@@ -478,7 +478,7 @@ public:
     }
 #elif WTF_CPU_ARM_TRADITIONAL && WTF_OS_LINUX && WTF_COMPILER_RVCT
     static __asm void cacheFlush(void* code, size_t size);
-#elif WTF_CPU_ARM_TRADITIONAL && (WTF_OS_LINUX || WTF_OS_ANDROID) && WTF_COMPILER_GCC
+#elif WTF_CPU_ARM_TRADITIONAL && (WTF_OS_LINUX || WTF_OS_ANDROID || WTF_OS_NETBSD) && WTF_COMPILER_GCC
     static void cacheFlush(void* code, size_t size)
     {
         asm volatile (
