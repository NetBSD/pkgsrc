$NetBSD: patch-third__party_perfetto_src_base_file__utils.cc,v 1.4 2026/04/21 15:21:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/file_utils.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/perfetto/src/base/file_utils.cc
@@ -60,8 +60,11 @@
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
@@ -637,8 +640,11 @@ std::optional<uint64_t> GetFileSize(Plat
 
 // LinuxFileWatch
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 
 namespace {
 
