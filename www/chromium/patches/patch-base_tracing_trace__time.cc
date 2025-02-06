$NetBSD: patch-base_tracing_trace__time.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/tracing/trace_time.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/tracing/trace_time.cc
@@ -8,13 +8,19 @@
 #include "build/build_config.h"
 #include "third_party/perfetto/include/perfetto/base/time.h"
 
+#if BUILDFLAG(IS_FREEBSD)
+#define CLOCK_BOOTTIME CLOCK_UPTIME
+#elif BUILDFLAG(IS_NETBSD)
+#define CLOCK_BOOTTIME CLOCK_MONOTONIC
+#endif
+
 namespace base {
 namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   struct timespec ts;
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
   if (res != -1)
@@ -24,4 +30,4 @@ int64_t TraceBootTicksNow() {
 }
 
 }  // namespace tracing
-}  // namespace base
\ No newline at end of file
+}  // namespace base
