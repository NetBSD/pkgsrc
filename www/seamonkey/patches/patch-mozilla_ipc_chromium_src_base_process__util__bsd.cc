$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util__bsd.cc,v 1.12 2017/01/01 16:14:08 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util_bsd.cc.orig	2016-12-14 02:07:49.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util_bsd.cc
@@ -12,6 +12,10 @@
 #include <spawn.h>
 #include <sys/wait.h>
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
+
 #include <string>
 
 #include "nspr.h"
