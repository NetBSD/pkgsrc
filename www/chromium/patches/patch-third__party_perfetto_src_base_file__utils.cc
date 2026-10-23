$NetBSD: patch-third__party_perfetto_src_base_file__utils.cc,v 1.17 2026/10/23 15:05:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/file_utils.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ third_party/perfetto/src/base/file_utils.cc
@@ -61,8 +61,11 @@
 #include <unistd.h>
 #endif
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 // For inotify. QNX doesn't have full support for inotify_init1().
 #include <sys/inotify.h>
 #endif
@@ -784,8 +787,11 @@ std::optional<uint64_t> GetFileSize(int 
 
 // LinuxFileWatch
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 namespace {
 
