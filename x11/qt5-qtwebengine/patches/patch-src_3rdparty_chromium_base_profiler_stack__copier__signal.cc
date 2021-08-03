$NetBSD: patch-src_3rdparty_chromium_base_profiler_stack__copier__signal.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/profiler/stack_copier_signal.cc.orig	2020-07-15 18:55:48.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/stack_copier_signal.cc
@@ -4,10 +4,14 @@
 
 #include "base/profiler/stack_copier_signal.h"
 
+#if defined(OS_NETBSD)
+#include <sys/futex.h>
+#else
 #include <linux/futex.h>
+#include <syscall.h>
+#endif
 #include <signal.h>
 #include <sys/ucontext.h>
-#include <syscall.h>
 
 #include <atomic>
 
