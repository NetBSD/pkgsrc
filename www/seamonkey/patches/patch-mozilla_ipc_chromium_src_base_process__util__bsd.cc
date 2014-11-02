$NetBSD: patch-mozilla_ipc_chromium_src_base_process__util__bsd.cc,v 1.11 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/ipc/chromium/src/base/process_util_bsd.cc.orig	2014-10-14 06:36:14.000000000 +0000
+++ mozilla/ipc/chromium/src/base/process_util_bsd.cc
@@ -9,6 +9,9 @@
 #include <sys/wait.h>
 
 #include <fcntl.h>
+#if defined(OS_BSD)
+#include <kvm.h>
+#endif
 #include <unistd.h>
 
 #include <string>
