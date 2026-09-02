$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_thread__isolation_pkey.cc,v 1.25 2026/09/02 13:13:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc
@@ -17,7 +17,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
