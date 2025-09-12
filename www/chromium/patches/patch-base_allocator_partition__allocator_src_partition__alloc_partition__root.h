$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__root.h,v 1.3 2025/09/12 16:02:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_root.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_root.h
@@ -197,7 +197,7 @@ struct PartitionOptions {
   // system to configure PartitionAlloc.
   EnableToggle fewer_memory_regions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
       kEnabled;
 #else
       kDisabled;
