$NetBSD: patch-ipc_chromium_src_base_process__util.h,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- ipc/chromium/src/base/process_util.h.orig	2013-05-11 19:19:32.000000000 +0000
+++ ipc/chromium/src/base/process_util.h
@@ -13,7 +13,7 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
 #include <dirent.h>
 #include <limits.h>
 #include <sys/types.h>
@@ -32,6 +32,9 @@
 typedef PROCESSENTRY32 ProcessEntry;
 typedef IO_COUNTERS IoCounters;
 #elif defined(OS_POSIX)
+#ifndef NAME_MAX
+#define NAME_MAX _POSIX_NAME_MAX
+#endif
 // TODO(port): we should not rely on a Win32 structure.
 struct ProcessEntry {
   int pid;
@@ -317,7 +320,7 @@ class NamedProcessIterator {
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   DIR *procfs_dir_;
 #elif defined(OS_BSD)
   std::vector<ProcessEntry> content;
