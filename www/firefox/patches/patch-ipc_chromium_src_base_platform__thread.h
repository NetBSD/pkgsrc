$NetBSD: patch-ipc_chromium_src_base_platform__thread.h,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- ipc/chromium/src/base/platform_thread.h.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
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
