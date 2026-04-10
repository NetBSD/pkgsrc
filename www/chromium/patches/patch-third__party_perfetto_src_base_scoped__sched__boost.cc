$NetBSD: patch-third__party_perfetto_src_base_scoped__sched__boost.cc,v 1.13 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/scoped_sched_boost.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/perfetto/src/base/scoped_sched_boost.cc
@@ -18,8 +18,9 @@
 
 #include "perfetto/ext/base/status_macros.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 #include <sched.h>         // for 'SCHED_' macros and 'sched_' functions
 #include <sys/resource.h>  // for 'setpriority', 'getpriority', 'PRIO_PROCESS'
 #include <sys/types.h>     // for 'pid_t'
@@ -31,8 +32,9 @@
 
 namespace perfetto::base {
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
 
 namespace {
 constexpr pid_t kCurrentPid = 0;
