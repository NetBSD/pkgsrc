$NetBSD: patch-base_memory_protected__memory__posix.cc,v 1.1 2025/02/06 09:57:40 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/protected_memory_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/memory/protected_memory_posix.cc
@@ -6,7 +6,7 @@
 
 #include <sys/mman.h>
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -34,7 +34,7 @@ bool SetMemory(void* start, void* end, i
 }  // namespace
 
 namespace internal {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void CheckMemoryReadOnly(const void* ptr) {
   const uintptr_t page_start =
       bits::AlignDown(reinterpret_cast<uintptr_t>(ptr), GetPageSize());
