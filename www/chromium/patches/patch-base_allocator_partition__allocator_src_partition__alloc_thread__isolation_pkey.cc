$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_thread__isolation_pkey.cc,v 1.8 2025/10/16 19:43:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc
@@ -21,7 +21,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
