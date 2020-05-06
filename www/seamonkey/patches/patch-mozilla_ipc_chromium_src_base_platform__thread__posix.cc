$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread__posix.cc,v 1.6 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2020-02-17 23:37:52.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
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
