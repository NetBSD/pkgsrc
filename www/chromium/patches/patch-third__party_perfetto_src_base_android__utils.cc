$NetBSD: patch-third__party_perfetto_src_base_android__utils.cc,v 1.1 2026/03/14 12:40:42 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/android_utils.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/perfetto/src/base/android_utils.cc
@@ -36,8 +36,11 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 #include <sys/sysinfo.h>
 #endif
 
@@ -103,8 +106,11 @@ SystemInfo GetSystemInfo() {
   info.page_size = static_cast<uint32_t>(sysconf(_SC_PAGESIZE));
   info.num_cpus = static_cast<uint32_t>(sysconf(_SC_NPROCESSORS_CONF));
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
   // Use the Linux-specific sysinfo() system call on Linux and Android.
   // https://man7.org/linux/man-pages/man2/sysinfo.2.html
   struct sysinfo sys_info;
