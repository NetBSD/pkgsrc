$NetBSD: patch-third__party_perfetto_src_base_thread__task__runner.cc,v 1.12 2025/12/13 14:54:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/thread_task_runner.cc.orig	2025-11-19 21:40:05.000000000 +0000
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
