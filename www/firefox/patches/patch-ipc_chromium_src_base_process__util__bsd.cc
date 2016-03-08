$NetBSD: patch-ipc_chromium_src_base_process__util__bsd.cc,v 1.3 2016/03/08 21:32:52 ryoon Exp $

Darwin does not provide kvm_getprocs(3). The code for OS_MACOSX is
simply copied from process_util_mac.mm

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
