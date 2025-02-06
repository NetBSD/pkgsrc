$NetBSD: patch-third__party_perfetto_include_perfetto_base_thread__utils.h,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -34,6 +34,7 @@ __declspec(dllimport) unsigned long __st
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <pthread.h>
 #else
 #include <pthread.h>
 #endif
@@ -46,6 +47,11 @@ using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
   return gettid();
 }
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
+using PlatformThreadId = uint64_t;
+inline PlatformThreadId GetThreadId() {
+  return reinterpret_cast<uint64_t>(pthread_self());
+}
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX)
 using PlatformThreadId = pid_t;
 inline PlatformThreadId GetThreadId() {
