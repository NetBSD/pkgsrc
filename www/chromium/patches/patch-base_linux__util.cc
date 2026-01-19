$NetBSD: patch-base_linux__util.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/linux_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/linux_util.cc
@@ -163,10 +163,14 @@ void SetLinuxDistro(const std::string& d
 }
 
 bool GetThreadsForProcess(pid_t pid, std::vector<pid_t>* tids) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   // 25 > strlen("/proc//task") + strlen(base::NumberToString(INT_MAX)) + 1 = 22
   char buf[25];
   strings::SafeSPrintf(buf, "/proc/%d/task", pid);
   return GetThreadsFromProcessDir(buf, tids);
+#endif
 }
 
 bool GetThreadsForCurrentProcess(std::vector<pid_t>* tids) {
