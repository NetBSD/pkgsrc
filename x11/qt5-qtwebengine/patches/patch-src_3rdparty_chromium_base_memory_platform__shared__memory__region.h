$NetBSD: patch-src_3rdparty_chromium_base_memory_platform__shared__memory__region.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/memory/platform_shared_memory_region.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/memory/platform_shared_memory_region.h
@@ -27,7 +27,7 @@
 #include "base/files/scoped_file.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 namespace content {
 class SandboxIPCHandler;
 }
@@ -120,7 +120,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
     kMaxValue = GET_SHMEM_TEMP_DIR_FAILURE
   };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Structure to limit access to executable region creation.
   struct ExecutableRegion {
    private:
@@ -264,7 +264,7 @@ class BASE_EXPORT PlatformSharedMemoryRe
                            CheckPlatformHandlePermissionsCorrespondToMode);
   static PlatformSharedMemoryRegion Create(Mode mode,
                                            size_t size
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
                                            ,
                                            bool executable = false
 #endif
