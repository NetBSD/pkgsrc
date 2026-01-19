$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__config.h,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_config.h
@@ -56,8 +56,8 @@ static_assert(sizeof(void*) != 8, "");
 // POSIX is not only UNIX, e.g. macOS and other OSes. We do use Linux-specific
 // features such as futex(2).
 #define PA_CONFIG_HAS_LINUX_KERNEL()                      \
-  (PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-   PA_BUILDFLAG(IS_ANDROID))
+  ((PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
+   PA_BUILDFLAG(IS_ANDROID)) && !PA_BUILDFLAG(IS_NETBSD))
 
 // Need TLS support.
 #define PA_CONFIG_THREAD_CACHE_SUPPORTED() \
@@ -171,7 +171,7 @@ constexpr bool kUseLazyCommit = false;
 // macOS, where it yielded no beenefit (nor any real downside).
 constexpr bool kUseFewerMemoryRegions =
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_ANDROID) || \
-    PA_BUILDFLAG(IS_CHROMEOS)
+    PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
     true;
 #else
     false;
@@ -181,7 +181,7 @@ constexpr bool kUseFewerMemoryRegions =
 // This may be required on more platforms in the future.
 #define PA_CONFIG_HAS_ATFORK_HANDLER()                 \
   (PA_BUILDFLAG(IS_APPLE) || PA_BUILDFLAG(IS_LINUX) || \
-   PA_BUILDFLAG(IS_CHROMEOS))
+   PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD))
 
 #if PA_BUILDFLAG(MOVE_METADATA_OUT_OF_GIGACAGE_FOR_64_BITS_POINTERS) && \
     PA_BUILDFLAG(HAS_64_BIT_POINTERS)
@@ -238,7 +238,7 @@ constexpr bool kUseFewerMemoryRegions =
 // Also enabled on ARM64 macOS and iOS, as the 16kiB pages on this platform lead
 // to larger slot spans.
 #if PA_BUILDFLAG(IS_LINUX) || \
-    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64))
+    (PA_BUILDFLAG(IS_APPLE) && PA_BUILDFLAG(PA_ARCH_CPU_ARM64)) || PA_BUILDFLAG(IS_BSD)
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 1
 #else
 #define PA_CONFIG_PREFER_SMALLER_SLOT_SPANS() 0
