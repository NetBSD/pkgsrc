$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_threading_platform__thread__posix.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_posix.cc
@@ -23,7 +23,7 @@
 #include "partition_alloc/partition_alloc_base/logging.h"
 #include "partition_alloc/partition_alloc_base/threading/platform_thread_internal_posix.h"
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 #include <sys/syscall.h>
 #include <atomic>
 #endif
