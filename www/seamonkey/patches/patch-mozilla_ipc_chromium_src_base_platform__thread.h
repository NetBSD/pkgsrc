$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread.h,v 1.4 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread.h.orig	2012-08-27 04:49:15.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread.h
@@ -22,9 +22,11 @@ typedef void* PlatformThreadHandle;  // 
 #elif defined(OS_POSIX)
 #include <pthread.h>
 typedef pthread_t PlatformThreadHandle;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_OPENBSD)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_BSD)
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_MACOSX)
 #include <mach/mach.h>
 typedef mach_port_t PlatformThreadId;
