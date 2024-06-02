$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_partition__alloc__constants.h,v 1.1 2024/06/02 11:34:20 markd Exp $

ICU75 fix - from ArchLinux

--- src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_constants.h.orig	2023-05-05 08:39:51.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/partition_alloc_constants.h
@@ -194,7 +194,7 @@ NumPartitionPagesPerSuperPage() {
 //
 // __STDCPP_DEFAULT_NEW_ALIGNMENT__ is C++17. As such, it is not defined on all
 // platforms, as Chrome's requirement is C++14 as of 2020.
-#if defined(__STDCPP_DEFAULT_NEW_ALIGNMENT__)
+#if 0
 static constexpr size_t kAlignment =
     std::max(alignof(std::max_align_t), __STDCPP_DEFAULT_NEW_ALIGNMENT__);
 #else
