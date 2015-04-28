$NetBSD: patch-ipc_chromium_src_base_atomicops.h,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- ipc/chromium/src/base/atomicops.h.orig	2015-04-10 17:59:48.000000000 +0000
+++ ipc/chromium/src/base/atomicops.h
@@ -52,7 +52,11 @@ typedef Atomic64 AtomicWord;
 typedef Atomic32 AtomicWord;
 #endif // ARCH_CPU_64_BITS
 #else
+#ifdef __arm__
+typedef Atomic32 AtomicWord;
+#else
 typedef intptr_t AtomicWord;
+#endif
 #endif // OS_OPENBSD
 
 // Atomically execute:
