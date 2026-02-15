$NetBSD: patch-base_atomicops.h,v 1.15 2026/02/15 09:03:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/atomicops.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/atomicops.h
@@ -72,7 +72,11 @@ typedef intptr_t Atomic64;
 
 // Use AtomicWord for a machine-sized pointer.  It will use the Atomic32 or
 // Atomic64 routines below, depending on your architecture.
+#if !defined(OS_OPENBSD) && defined(__i386__)
+typedef Atomic32 AtomicWord;
+#else
 typedef intptr_t AtomicWord;
+#endif
 
 // Atomically execute:
 //      result = *ptr;
