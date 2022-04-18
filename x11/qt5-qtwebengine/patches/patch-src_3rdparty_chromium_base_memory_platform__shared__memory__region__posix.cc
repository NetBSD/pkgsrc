$NetBSD: patch-src_3rdparty_chromium_base_memory_platform__shared__memory__region__posix.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/memory/platform_shared_memory_region_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/memory/platform_shared_memory_region_posix.cc
@@ -70,7 +70,7 @@ FDPair ScopedFDPair::get() const {
   return {fd.get(), readonly_fd.get()};
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 ScopedFD PlatformSharedMemoryRegion::ExecutableRegion::CreateFD(size_t size) {
   PlatformSharedMemoryRegion region =
@@ -204,7 +204,7 @@ bool PlatformSharedMemoryRegion::MapAtIn
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                                               ,
                                                               bool executable
 #endif
