$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_page__allocator.h,v 1.25 2026/09/02 13:13:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -279,7 +279,7 @@ bool DecommitAndZeroSystemPages(void* ad
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
