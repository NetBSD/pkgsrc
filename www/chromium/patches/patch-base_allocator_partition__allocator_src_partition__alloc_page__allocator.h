$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_page__allocator.h,v 1.5 2025/08/13 07:44:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -273,7 +273,7 @@ bool DecommitAndZeroSystemPages(void* ad
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
