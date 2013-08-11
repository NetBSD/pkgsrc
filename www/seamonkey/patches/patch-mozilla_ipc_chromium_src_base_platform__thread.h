$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread.h,v 1.8 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread.h.orig	2013-08-04 03:05:29.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread.h
@@ -25,6 +25,9 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX) || defined(OS_OPENBSD)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_SOLARIS)
+#include <sys/lwp.h>
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_BSD)
 #include <sys/types.h>
 typedef lwpid_t PlatformThreadId;
