$NetBSD: patch-base_memory_platform__shared__memory__region__posix.cc,v 1.28 2026/10/02 11:43:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/platform_shared_memory_region_posix.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ base/memory/platform_shared_memory_region_posix.cc
@@ -263,7 +263,7 @@ bool PlatformSharedMemoryRegion::Convert
 // static
 PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode,
                                                               size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                                               ,
                                                               bool executable
 #endif
@@ -299,7 +299,7 @@ PlatformSharedMemoryRegion PlatformShare
   // flag.
   FilePath directory;
   if (!GetShmemTempDir(
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
           executable,
 #else
           false /* executable */,
