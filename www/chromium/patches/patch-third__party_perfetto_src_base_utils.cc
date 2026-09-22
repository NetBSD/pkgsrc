$NetBSD: patch-third__party_perfetto_src_base_utils.cc,v 1.26 2026/09/22 13:41:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/utils.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ third_party/perfetto/src/base/utils.cc
@@ -43,11 +43,16 @@
 #include <mach/vm_page_size.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 #include <sys/sysctl.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+#include <sys/param.h>
+#endif
+
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 
@@ -151,6 +156,7 @@ uid_t GetCurrentUserId() {
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   return geteuid();
 #else
@@ -244,14 +250,29 @@ void Daemonize(std::function<int(pid_t)>
 
 std::string GetCurExecutablePath() {
   std::string self_path;
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) ||   \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FUCHSIA)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   char buf[PATH_MAX];
   ssize_t size = readlink("/proc/self/exe", buf, sizeof(buf));
   PERFETTO_CHECK(size != -1);
   // readlink does not null terminate.
   self_path = std::string(buf, static_cast<size_t>(size));
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD)
+#if (OpenBSD >= 202610)
+  char execpath[PATH_MAX];
+  int ret = getexecpath(execpath, sizeof(execpath));
+  PERFETTO_CHECK(ret != 0);
+  self_path = std::string(execpath);
+#else
+  char *buf;
+  const char *cpath = "@PREFIX@/lib/chromium/chrome";
+  if ((buf = getenv("CHROME_EXE_PATH")) != NULL)
+    self_path = std::string(buf);
+  else
+    self_path = std::string(cpath);
+#endif
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   uint32_t size = 0;
   PERFETTO_CHECK(_NSGetExecutablePath(nullptr, &size));
@@ -261,14 +282,21 @@ std::string GetCurExecutablePath() {
   char buf[MAX_PATH];
   auto len = ::GetModuleFileNameA(nullptr /*current*/, buf, sizeof(buf));
   self_path = std::string(buf, len);
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) || PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
   char buf[PATH_MAX];
   int mib[4], ret;
   size_t len = sizeof(buf);
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC_ARGS;
+  mib[2] = getpid();
+  mib[3] = KERN_PROC_PATHNAME;
+#else
   mib[0] = CTL_KERN;
   mib[1] = KERN_PROC;
   mib[2] = KERN_PROC_PATHNAME;
   mib[3] = -1;
+#endif
   ret = sysctl(mib, 4, buf, &len, NULL, 0);
   PERFETTO_CHECK(ret == 0);
   // This returns the full path; need to trim the executable
@@ -315,7 +343,8 @@ void AlignedFree(void* ptr) {
 }
 
 bool IsSyncMemoryTaggingEnabled() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // Compute only once per lifetime of the process.
   static bool cached_value = [] {
