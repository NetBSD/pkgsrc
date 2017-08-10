$NetBSD: patch-ipc_chromium_src_base_platform__thread.h,v 1.6 2017/08/10 14:46:15 ryoon Exp $

* Support Solaris

--- ipc/chromium/src/base/platform_thread.h.orig	2017-07-31 16:20:47.000000000 +0000
+++ ipc/chromium/src/base/platform_thread.h
@@ -27,6 +27,9 @@ typedef pthread_t PlatformThreadHandle;
 #if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_SOLARIS) || defined(__GLIBC__)
 #include <unistd.h>
 typedef pid_t PlatformThreadId;
+#elif defined(OS_SOLARIS)
+#include <sys/lwp.h>
+typedef lwpid_t PlatformThreadId;
 #elif defined(OS_BSD)
 #include <sys/types.h>
 typedef lwpid_t PlatformThreadId;
