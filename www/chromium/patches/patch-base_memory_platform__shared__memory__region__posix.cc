$NetBSD: patch-base_memory_platform__shared__memory__region__posix.cc,v 1.8 2025/10/16 19:43:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/platform_shared_memory_region_posix.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -172,7 +172,7 @@ bool PlatformSharedMemoryRegion::Convert
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -197,7 +197,7 @@ PlatformSharedMemoryRegion PlatformShare
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           executable,
 #else
           false /* executable */,
