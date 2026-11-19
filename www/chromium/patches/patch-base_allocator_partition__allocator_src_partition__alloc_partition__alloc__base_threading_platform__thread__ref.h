$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_threading_platform__thread__ref.h,v 1.1 2026/11/19 19:45:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread_ref.h
@@ -48,7 +48,7 @@ class PlatformThreadRef {
 
   bool is_null() const { return id_ == 0; }
 
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
   template <typename Hasher>
   size_t hash_value() const {
     return Hasher()(reinterpret_cast<uintptr_t>(id_));
