$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.14 2025/10/27 14:24:33 ryoon Exp $

* Support NetBSD

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2023-07-20 18:06:23.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,9 @@
 #if defined(XP_DARWIN)
 #  include <mach/mach.h>
 #elif defined(XP_NETBSD)
+_Pragma("GCC visibility push(default)")
 #  include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(XP_LINUX)
 #  include <sys/syscall.h>
 #  include <sys/prctl.h>
