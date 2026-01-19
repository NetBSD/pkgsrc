$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_page__allocator__internals__posix.h,v 1.14 2026/01/19 16:14:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.h
@@ -322,8 +322,12 @@ bool TryRecommitSystemPagesInternal(
 
 void DiscardSystemPagesInternal(uintptr_t address, size_t length) {
   void* ptr = reinterpret_cast<void*>(address);
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
+#if PA_BUILDFLAG(IS_BSD)
+  int ret = madvise(ptr, length, MADV_FREE);
+#else
   int ret = madvise(ptr, length, MADV_FREE_REUSABLE);
+#endif
   if (ret) {
     // MADV_FREE_REUSABLE sometimes fails, so fall back to MADV_DONTNEED.
     ret = madvise(ptr, length, MADV_DONTNEED);
