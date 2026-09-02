$NetBSD: patch-base_memory_platform__shared__memory__region.h,v 1.25 2026/09/02 13:13:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/platform_shared_memory_region.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ base/memory/platform_shared_memory_region.h
@@ -104,7 +104,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
 #if BUILDFLAG(IS_FUCHSIA)
     kNotVmo,
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     kFcntlFailed,
     kReadOnlyFdNotReadOnly,
     kUnexpectedReadOnlyFd,
@@ -249,7 +249,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                                            ,
                                            bool executable = false
 #endif
