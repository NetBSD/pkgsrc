$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__tls.h,v 1.1 2026/11/08 15:38:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_tls.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_tls.h
@@ -65,9 +65,16 @@ constexpr inline size_t kMaxThreadCacheI
 constexpr inline uintptr_t kTombstone = 1;
 constexpr inline uintptr_t kTombstoneMask = ~kTombstone;
 
+/* NetBSD doesn't use futex, so ::Lock wraps a pthread_mutex_t
+ * instead of using SpinningMutex. This makes ThreadCache
+ * 32 bytes larger than with SpinningMutex.
+ */
 #if PA_BUILDFLAG(HAS_64_BIT_POINTERS)
 constexpr inline size_t kThreadCacheStorageSize =
     1512 + (PA_CONFIG(THREAD_CACHE_ALLOC_STATS) ? 896 : 0) +
+#if PA_BUILDFLAG(IS_NETBSD)
+    32 +
+#endif
     ((PA_BUILDFLAG(DCHECKS_ARE_ON) ||
       PA_BUILDFLAG(ENABLE_PARTITION_LOCK_REENTRANCY_CHECK))
          ? 8
