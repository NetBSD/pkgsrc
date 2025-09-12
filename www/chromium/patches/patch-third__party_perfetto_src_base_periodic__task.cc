$NetBSD: patch-third__party_perfetto_src_base_periodic__task.cc,v 1.7 2025/09/12 16:02:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/periodic_task.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/perfetto/src/base/periodic_task.cc
@@ -24,7 +24,7 @@
 #include "perfetto/base/time.h"
 #include "perfetto/ext/base/file_utils.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
 #include <sys/timerfd.h>
 #endif
@@ -44,7 +44,7 @@ uint32_t GetNextDelayMs(const TimeMillis
 }
 
 ScopedPlatformHandle CreateTimerFd(const PeriodicTask::Args& args) {
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     (PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) && __ANDROID_API__ >= 19)
   ScopedPlatformHandle tfd(
       timerfd_create(CLOCK_BOOTTIME, TFD_CLOEXEC | TFD_NONBLOCK));
