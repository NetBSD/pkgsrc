$NetBSD: patch-v8_src_base_atomicops.h,v 1.1 2025/02/06 09:58:36 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/atomicops.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ v8/src/base/atomicops.h
@@ -57,10 +57,10 @@ using Atomic64 = SbAtomic64;
 using Atomic8 = char;
 using Atomic16 = int16_t;
 using Atomic32 = int32_t;
-#if defined(V8_HOST_ARCH_64_BIT)
+#if defined(V8_HOST_ARCH_64_BIT) || defined(V8_OS_OPENBSD)
 // We need to be able to go between Atomic64 and AtomicWord implicitly.  This
 // means Atomic64 and AtomicWord should be the same type on 64-bit.
-#if defined(__ILP32__)
+#if defined(__ILP32__) && !defined(V8_OS_OPENBSD)
 using Atomic64 = int64_t;
 #else
 using Atomic64 = intptr_t;
@@ -266,7 +266,7 @@ inline Atomic32 SeqCst_Load(volatile con
                                    std::memory_order_seq_cst);
 }
 
-#if defined(V8_HOST_ARCH_64_BIT)
+#if defined(V8_HOST_ARCH_64_BIT) || defined(V8_OS_OPENBSD)
 
 inline Atomic64 Relaxed_CompareAndSwap(volatile Atomic64* ptr,
                                        Atomic64 old_value, Atomic64 new_value) {
