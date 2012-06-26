$NetBSD: patch-libev_ev.c,v 1.1 2012/06/26 20:14:31 riastradh Exp $

Use the same memory fences with llvm-gcc as with gcc and clang.

--- libev/ev.c.orig	2012-01-19 17:55:00.000000000 +0000
+++ libev/ev.c
@@ -541,7 +541,7 @@ struct signalfd_siginfo
 #endif
 
 #ifndef ECB_MEMORY_FENCE
-  #if ECB_GCC_VERSION(2,5) || defined(__INTEL_COMPILER) || defined(__clang__) || __SUNPRO_C >= 0x5110 || __SUNPRO_CC >= 0x5110
+  #if ECB_GCC_VERSION(2,5) || defined(__INTEL_COMPILER) || defined(__llvm__) || defined(__clang__) || __SUNPRO_C >= 0x5110 || __SUNPRO_CC >= 0x5110
     #if __i386 || __i386__
       #define ECB_MEMORY_FENCE         __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory")
       #define ECB_MEMORY_FENCE_ACQUIRE ECB_MEMORY_FENCE /* non-lock xchg might be enough */
