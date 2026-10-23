$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__constants.h,v 1.31 2026/10/23 15:05:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_constants.h
@@ -235,7 +235,7 @@ constexpr size_t kMinDirectMappedDownsiz
 // TODO(casey.smalley@arm.com): under 64k pages we can end up in a situation
 // where a normal slot span will be large enough to contain multiple items,
 // but the address will go over the final partition page after being aligned.
-#if PA_BUILDFLAG(IS_LINUX) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
+#if (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
 inline constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 4;
 #else
 inline constexpr size_t kMaxSupportedAlignment = kSuperPageSize / 2;
