$NetBSD: patch-base_process_process__handle__freebsd.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_handle_freebsd.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/process/process_handle_freebsd.cc
@@ -3,6 +3,7 @@
 // found in the LICENSE file.
 
 #include "base/process/process_handle.h"
+#include "base/files/file_util.h"
 
 #include <limits.h>
 #include <stddef.h>
@@ -20,11 +21,14 @@ namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, process};
 
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
     return -1;
+
+  if (length < sizeof(struct kinfo_proc))
+    return -1;
   }
 
   return info.ki_ppid;
