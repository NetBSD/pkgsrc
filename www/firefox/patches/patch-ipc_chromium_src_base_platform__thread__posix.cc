$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.9 2017/08/10 14:46:15 ryoon Exp $

* Support NetBSD
* Support Solaris

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2017-07-31 16:20:47.000000000 +0000
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
