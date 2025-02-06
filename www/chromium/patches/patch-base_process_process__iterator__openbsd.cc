$NetBSD: patch-base_process_process__iterator__openbsd.cc,v 1.1 2025/02/06 09:57:41 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_iterator_openbsd.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/process/process_iterator_openbsd.cc
@@ -6,6 +6,9 @@
 
 #include <errno.h>
 #include <stddef.h>
+#include <unistd.h>
+#include <sys/param.h>
+#include <sys/proc.h>
 #include <sys/sysctl.h>
 
 #include "base/logging.h"
@@ -16,12 +19,13 @@ namespace base {
 
 ProcessIterator::ProcessIterator(const ProcessFilter* filter)
     : filter_(filter) {
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_UID, getuid(),
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_UID, static_cast<int>(getuid()),
                 sizeof(struct kinfo_proc), 0 };
 
   bool done = false;
   int try_num = 1;
   const int max_tries = 10;
+  size_t num_of_kinfo_proc;
 
   do {
     size_t len = 0;
@@ -30,7 +34,7 @@ ProcessIterator::ProcessIterator(const P
       kinfo_procs_.resize(0);
       done = true;
     } else {
-      size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+      num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
       // Leave some spare room for process table growth (more could show up
       // between when we check and now)
       num_of_kinfo_proc += 16;
@@ -46,7 +50,7 @@ ProcessIterator::ProcessIterator(const P
         }
       } else {
         // Got the list, just make sure we're sized exactly right
-        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+        num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
         kinfo_procs_.resize(num_of_kinfo_proc);
         done = true;
       }
