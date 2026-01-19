$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_debug_stack__trace__posix.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/stack_trace_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/stack_trace_posix.cc
@@ -18,11 +18,11 @@
 #include "partition_alloc/partition_alloc_base/posix/eintr_wrapper.h"
 #include "partition_alloc/partition_alloc_base/strings/safe_sprintf.h"
 
-#if !PA_BUILDFLAG(IS_ANDROID) && !PA_BUILDFLAG(IS_APPLE)
+#if !PA_BUILDFLAG(IS_ANDROID) && !PA_BUILDFLAG(IS_APPLE) && !PA_BUILDFLAG(IS_BSD)
 #include <link.h>  // For ElfW() macro.
 #endif
 
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
 #include <dlfcn.h>
 #endif
 
@@ -30,7 +30,7 @@ namespace partition_alloc::internal::bas
 
 namespace {
 
-#if !PA_BUILDFLAG(IS_APPLE)
+#if !PA_BUILDFLAG(IS_APPLE) && !PA_BUILDFLAG(IS_BSD)
 
 // On Android the 'open' function has two versions:
 // int open(const char *pathname, int flags);
@@ -374,7 +374,7 @@ void PrintStackTraceInternal(const void*
 }
 #endif  // !PA_BUILDFLAG(IS_APPLE)
 
-#if PA_BUILDFLAG(IS_APPLE)
+#if PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_BSD)
 // Since /proc/self/maps is not available, use dladdr() to obtain module
 // names and offsets inside the modules from the given addresses.
 void PrintStackTraceInternal(const void* const* trace, size_t size) {
