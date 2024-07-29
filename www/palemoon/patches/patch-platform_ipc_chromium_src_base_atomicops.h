$NetBSD: patch-platform_ipc_chromium_src_base_atomicops.h,v 1.1 2024/07/29 18:13:48 nia Exp $

Fixes for NetBSD/arm, taken from www/firefox52

--- platform/ipc/chromium/src/base/atomicops.h.orig	2024-07-10 08:54:53.000000000 +0000
+++ platform/ipc/chromium/src/base/atomicops.h
@@ -46,7 +46,7 @@ typedef int64_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
-#ifdef OS_OPENBSD
+#if defined(OS_OPENBSD) || (defined(OS_NETBSD) && defined(ARCH_CPU_ARM_FAMILY))
 #ifdef ARCH_CPU_64_BITS
 typedef Atomic64 AtomicWord;
 #else
