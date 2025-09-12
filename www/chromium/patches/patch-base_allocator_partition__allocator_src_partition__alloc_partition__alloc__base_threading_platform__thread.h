$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_partition__alloc__base_threading_platform__thread.h,v 1.7 2025/09/12 16:02:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/threading/platform_thread.h
@@ -43,6 +43,8 @@ typedef DWORD PlatformThreadId;
 typedef zx_handle_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_APPLE)
 typedef mach_port_t PlatformThreadId;
+#elif PA_BUILDFLAG(IS_BSD)
+typedef uint64_t PlatformThreadId;
 #elif PA_BUILDFLAG(IS_POSIX)
 typedef pid_t PlatformThreadId;
 #endif
