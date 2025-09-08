$NetBSD: patch-base_allocator_partition__alloc__features.cc,v 1.4 2025/09/08 13:24:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_alloc_features.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/allocator/partition_alloc_features.cc
@@ -154,7 +154,7 @@ BASE_FEATURE(kPartitionAllocEventuallyZe
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
