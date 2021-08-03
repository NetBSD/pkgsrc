$NetBSD: patch-src_3rdparty_chromium_base_memory_platform__shared__memory__region__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/memory/platform_shared_memory_region_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/memory/platform_shared_memory_region_posix.cc
@@ -70,7 +70,7 @@ FDPair ScopedFDPair::get() const {
   return {fd.get(), readonly_fd.get()};
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 ScopedFD PlatformSharedMemoryRegion::ExecutableRegion::CreateFD(size_t size) {
   PlatformSharedMemoryRegion region =
@@ -204,7 +204,7 @@ bool PlatformSharedMemoryRegion::MapAtIn
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
                                                               ,
                                                               bool executable
 #endif
