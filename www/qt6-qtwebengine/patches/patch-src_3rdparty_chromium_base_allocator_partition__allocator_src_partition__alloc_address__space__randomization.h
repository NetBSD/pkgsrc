$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_src_partition__alloc_address__space__randomization.h,v 1.1 2025/12/21 09:38:12 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/address_space_randomization.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/address_space_randomization.h
@@ -38,7 +38,7 @@ AslrMask(uintptr_t bits) {
 
 #if PA_BUILDFLAG(PA_ARCH_CPU_64_BITS)
 
-  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
+  #if defined(MEMORY_TOOL_REPLACES_ALLOCATOR) && !PA_BUILDFLAG(IS_BSD)
 
     // We shouldn't allocate system pages at all for sanitizer builds. However,
     // we do, and if random hint addresses interfere with address ranges
@@ -125,7 +125,7 @@ AslrMask(uintptr_t bits) {
         return AslrAddress(0x20000000ULL);
       }
     #elif PA_BUILDFLAG(PA_ARCH_CPU_ARM64)
-      #if PA_BUILDFLAG(IS_LINUX)
+      #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_BSD)
 
       // Linux on arm64 can use 39, 42, 48, or 52-bit user space, depending on
       // page size and number of levels of translation pages used. We use
