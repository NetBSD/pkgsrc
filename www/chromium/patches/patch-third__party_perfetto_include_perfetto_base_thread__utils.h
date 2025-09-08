$NetBSD: patch-third__party_perfetto_include_perfetto_base_thread__utils.h,v 1.6 2025/09/08 13:24:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/base/thread_utils.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/perfetto/include/perfetto/base/thread_utils.h
@@ -37,6 +37,7 @@ __declspec(dllimport) unsigned long __st
 #include <sys/syscall.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <pthread.h>
 #else
 #include <pthread.h>
 #endif
@@ -50,6 +51,11 @@ using PlatformThreadId = pid_t;
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
