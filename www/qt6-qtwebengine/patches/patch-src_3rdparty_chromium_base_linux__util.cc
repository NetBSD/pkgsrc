$NetBSD: patch-src_3rdparty_chromium_base_linux__util.cc,v 1.1 2025/12/21 09:38:13 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/linux_util.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/base/linux_util.cc
@@ -164,10 +164,14 @@ void SetLinuxDistro(const std::string& d
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
