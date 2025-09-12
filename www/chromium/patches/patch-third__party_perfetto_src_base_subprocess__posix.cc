$NetBSD: patch-third__party_perfetto_src_base_subprocess__posix.cc,v 1.7 2025/09/12 16:02:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/subprocess_posix.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/perfetto/src/base/subprocess_posix.cc
@@ -35,7 +35,8 @@
 #include <thread>
 #include <tuple>
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
@@ -64,7 +65,8 @@ struct ChildProcessArgs {
 // Don't add any dynamic allocation in this function. This will be invoked
 // under a fork(), potentially in a state where the allocator lock is held.
 void __attribute__((noreturn)) ChildProcess(ChildProcessArgs* args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
   // In no case we want a child process to outlive its parent process. This is
   // relevant for tests, so that a test failure/crash doesn't leave child
