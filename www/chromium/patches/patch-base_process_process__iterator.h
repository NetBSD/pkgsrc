$NetBSD: patch-base_process_process__iterator.h,v 1.1 2025/02/06 09:57:41 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_iterator.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/process/process_iterator.h
@@ -24,7 +24,7 @@
 #include <windows.h>
 
 #include <tlhelp32.h>
-#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
 #include <sys/sysctl.h>
 #elif BUILDFLAG(IS_FREEBSD)
 #include <sys/user.h>
@@ -116,7 +116,11 @@ class BASE_EXPORT ProcessIterator {
   HANDLE snapshot_;
   bool started_iteration_ = false;
 #elif BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
+# if BUILDFLAG(IS_NETBSD)
+  std::vector<kinfo_proc2> kinfo_procs_;
+# else
   std::vector<kinfo_proc> kinfo_procs_;
+# endif
   size_t index_of_kinfo_proc_ = 0;
 #elif BUILDFLAG(IS_POSIX)
   struct DIRClose {
