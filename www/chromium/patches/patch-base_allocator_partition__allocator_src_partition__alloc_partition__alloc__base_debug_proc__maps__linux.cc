$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_debug_proc__maps__linux.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -19,7 +19,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
