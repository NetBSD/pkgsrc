$NetBSD: patch-src_3rdparty_chromium_base_process_process__iterator.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_iterator.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_iterator.h
@@ -24,7 +24,7 @@
 #if defined(OS_WIN)
 #include <windows.h>
 #include <tlhelp32.h>
-#elif defined(OS_APPLE) || defined(OS_OPENBSD)
+#elif defined(OS_APPLE) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/sysctl.h>
 #elif defined(OS_FREEBSD)
 #include <sys/user.h>
@@ -111,9 +111,12 @@ class BASE_EXPORT ProcessIterator {
 #if defined(OS_WIN)
   HANDLE snapshot_;
   bool started_iteration_;
-#elif defined(OS_APPLE) || defined(OS_BSD)
+#elif defined(OS_APPLE) || defined(OS_FREEBSD)
   std::vector<kinfo_proc> kinfo_procs_;
   size_t index_of_kinfo_proc_;
+#elif defined(OS_NETBSD)
+  std::vector<kinfo_proc2> kinfo_procs_;
+  size_t index_of_kinfo_proc_;
 #elif defined(OS_POSIX) || defined(OS_FUCHSIA)
   DIR* procfs_dir_;
 #endif
