$NetBSD: patch-third__party_perfetto_src_base_thread__task__runner.cc,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/thread_task_runner.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/perfetto/src/base/thread_task_runner.cc
@@ -27,7 +27,8 @@
 #include "perfetto/ext/base/lock_free_task_runner.h"
 #include "perfetto/ext/base/thread_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/prctl.h>
 #endif
