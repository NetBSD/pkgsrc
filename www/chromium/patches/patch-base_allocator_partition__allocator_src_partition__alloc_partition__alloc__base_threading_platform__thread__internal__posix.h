$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_threading_platform__thread__internal__posix.h,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h
@@ -15,7 +15,7 @@
 
 namespace partition_alloc::internal::base::internal {
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 // Current thread id is cached in thread local storage for performance reasons.
 // In some rare cases it's important to invalidate that cache explicitly (e.g.
 // after going through clone() syscall which does not call pthread_atfork()
