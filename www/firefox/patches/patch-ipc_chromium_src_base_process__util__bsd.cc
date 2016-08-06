$NetBSD: patch-ipc_chromium_src_base_process__util__bsd.cc,v 1.5 2016/08/06 08:46:59 ryoon Exp $

--- ipc/chromium/src/base/process_util_bsd.cc.orig	2016-07-25 20:22:06.000000000 +0000
+++ ipc/chromium/src/base/process_util_bsd.cc
@@ -10,6 +10,10 @@
 #include <spawn.h>
 #include <sys/wait.h>
 
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
+
 #include <string>
 
 #include "nspr.h"
