$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__alloc__features.cc,v 1.1 2026/04/30 06:39:35 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_alloc_features.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_alloc_features.cc
@@ -157,7 +157,7 @@ BASE_FEATURE(kPartitionAllocEventuallyZe
 // disabled elsewhere (for now). Does not apply to Windows.
 BASE_FEATURE(kPartitionAllocFewerMemoryRegions,
              "PartitionAllocFewerMemoryRegions",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              FEATURE_ENABLED_BY_DEFAULT);
 #else
              FEATURE_DISABLED_BY_DEFAULT);
