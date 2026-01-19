$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_page__allocator__internals__posix.cc,v 1.14 2026/01/19 16:14:05 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -44,7 +44,7 @@ uint32_t SecTaskGetCodeSignStatus(SecTas
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) ||                                        \
     (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && \
-     __has_include(<sys/ifunc.h>))
+     __has_include(<sys/ifunc.h>) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
