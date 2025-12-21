$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_src_partition__alloc_page__allocator.h,v 1.1 2025/12/21 09:38:12 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/page_allocator.h
@@ -269,7 +269,7 @@ bool DecommitAndZeroSystemPages(void* ad
 // recommitted. Do not assume that this will not change over time.
 constexpr PA_COMPONENT_EXPORT(
     PARTITION_ALLOC) bool DecommittedMemoryIsAlwaysZeroed() {
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   return false;
 #else
   return true;
