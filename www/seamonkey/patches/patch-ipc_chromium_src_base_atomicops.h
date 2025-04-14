$NetBSD: patch-ipc_chromium_src_base_atomicops.h,v 1.1 2025/04/14 15:33:04 nia Exp $

Support NetBSD/aarch64.

--- ipc/chromium/src/base/atomicops.h.orig	2025-03-07 12:19:55.639506726 +0000
+++ ipc/chromium/src/base/atomicops.h
@@ -47,7 +47,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
@@ -55,7 +55,7 @@ typedef Atomic32 AtomicWord;
 #endif // ARCH_CPU_64_BITS
 #else
 typedef intptr_t AtomicWord;
-#endif // OS_OPENBSD
+#endif // defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 
 // Atomically execute:
 //      result = *ptr;
