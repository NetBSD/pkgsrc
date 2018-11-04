$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.11 2018/11/04 00:38:44 ryoon Exp $

* Support NetBSD
* Support Solaris (we can't rely on pthread_setname_np so ignore it).

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2018-10-18 20:06:05.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,9 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
