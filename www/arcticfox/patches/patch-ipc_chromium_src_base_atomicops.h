$NetBSD: patch-ipc_chromium_src_base_atomicops.h,v 1.2 2025/05/06 21:22:41 nia Exp $

Fixes for NetBSD/arm, taken from www/firefox52

--- ipc/chromium/src/base/atomicops.h.orig	2025-03-13 13:33:35.000000000 +0000
+++ ipc/chromium/src/base/atomicops.h
@@ -47,7 +47,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && (defined(ARCH_CPU_ARM_FAMILY) || defined(ARCH_CPU_MIPS)))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
