$NetBSD: patch-third__party_perfetto_src_base_periodic__task.cc,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/periodic_task.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/perfetto/src/base/periodic_task.cc
@@ -24,9 +24,10 @@
 #include "perfetto/base/time.h"
 #include "perfetto/ext/base/file_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) ||           \
-    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
 #include <sys/timerfd.h>
 #endif
 
@@ -45,9 +46,10 @@ uint32_t GetNextDelayMs(const TimeMillis
 }
 
 ScopedPlatformHandle CreateTimerFd(const PeriodicTask::Args& args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD) ||           \
-    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
+    (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_OPENBSD) && !PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
   ScopedPlatformHandle tfd(
       timerfd_create(CLOCK_BOOTTIME, TFD_CLOEXEC | TFD_NONBLOCK));
   uint32_t phase_ms = GetNextDelayMs(GetBootTimeMs(), args);
