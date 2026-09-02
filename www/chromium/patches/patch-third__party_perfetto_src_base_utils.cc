$NetBSD: patch-third__party_perfetto_src_base_utils.cc,v 1.25 2026/09/02 13:13:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/utils.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ third_party/perfetto/src/base/utils.cc
@@ -47,7 +47,8 @@
 #include <sys/sysctl.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 
@@ -244,14 +245,22 @@ void Daemonize(std::function<int(pid_t)>
 
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
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+  char *buf;
+  const char *cpath = "@PREFIX@/lib/chromium/chrome";
+  if ((buf = getenv("CHROME_EXE_PATH")) != NULL)
+    self_path = std::string(buf);
+  else
+    self_path = std::string(cpath);
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   uint32_t size = 0;
   PERFETTO_CHECK(_NSGetExecutablePath(nullptr, &size));
@@ -315,7 +324,8 @@ void AlignedFree(void* ptr) {
 }
 
 bool IsSyncMemoryTaggingEnabled() {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // Compute only once per lifetime of the process.
   static bool cached_value = [] {
