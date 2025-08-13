$NetBSD: patch-base_allocator_partition__alloc__features.cc,v 1.3 2025/08/13 07:44:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_alloc_features.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ base/allocator/partition_alloc_features.cc
@@ -164,7 +164,7 @@ BASE_FEATURE(kPartitionAllocEventuallyZe
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
@@ -489,7 +489,7 @@ BASE_FEATURE(kPartitionAllocAdjustSizeWh
 #if PA_CONFIG(ENABLE_SHADOW_METADATA)
 BASE_FEATURE(kPartitionAllocShadowMetadata,
              "PartitionAllocShadowMetadata",
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
