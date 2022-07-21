$NetBSD: patch-ipc_chromium_src_base_platform__thread__posix.cc,v 1.1 2022/07/21 23:56:39 nia Exp $

* Support NetBSD
* Support Solaris (we can't rely on pthread_setname_np so ignore it).

--- ipc/chromium/src/base/platform_thread_posix.cc.orig	2019-03-07 16:53:35.000000000 +0000
+++ ipc/chromium/src/base/platform_thread_posix.cc
@@ -12,7 +12,9 @@
 #if defined(OS_MACOSX)
 #  include <mach/mach.h>
 #elif defined(OS_NETBSD)
-#  include <lwp.h>
+_Pragma("GCC visibility push(default)")
+#include <lwp.h>
+_Pragma("GCC visibility pop")
 #elif defined(OS_LINUX)
 #  include <sys/syscall.h>
 #  include <sys/prctl.h>
