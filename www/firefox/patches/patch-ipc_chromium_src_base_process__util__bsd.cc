$NetBSD: patch-ipc_chromium_src_base_process__util__bsd.cc,v 1.4 2016/06/16 12:08:21 ryoon Exp $

--- ipc/chromium/src/base/process_util_bsd.cc.orig	2016-02-25 23:01:54.000000000 +0000
+++ ipc/chromium/src/base/process_util_bsd.cc
@@ -10,6 +10,10 @@
 #include <spawn.h>
 #include <sys/wait.h>
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
+
 #include <string>
 
 #include "base/eintr_wrapper.h"
