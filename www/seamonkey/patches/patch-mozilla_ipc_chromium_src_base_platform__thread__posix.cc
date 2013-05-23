$NetBSD: patch-mozilla_ipc_chromium_src_base_platform__thread__posix.cc,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/ipc/chromium/src/base/platform_thread_posix.cc.orig	2013-05-03 03:07:57.000000000 +0000
+++ mozilla/ipc/chromium/src/base/platform_thread_posix.cc
@@ -10,7 +10,9 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #elif defined(OS_NETBSD)
+_Pragma("GCC visibility push(default)")
 #include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #include <sys/syscall.h>
 #include <sys/prctl.h>
