$NetBSD: patch-src_3rdparty_chromium_services_tracing_public_cpp_perfetto_trace__time.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.cc
@@ -12,13 +12,19 @@ namespace tracing {
 
 int64_t TraceBootTicksNow() {
   // On Windows and Mac, TRACE_TIME_TICKS_NOW() behaves like boottime already.
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   struct timespec ts;
+#if defined(OS_FREEBSD)
+  int res = clock_gettime(CLOCK_UPTIME, &ts);
+#elif defined(OS_NETBSD)
+  int res = clock_gettime(CLOCK_MONOTONIC, &ts);
+#else
   int res = clock_gettime(CLOCK_BOOTTIME, &ts);
+#endif
   if (res != -1)
     return static_cast<int64_t>(perfetto::base::FromPosixTimespec(ts).count());
 #endif
   return TRACE_TIME_TICKS_NOW().since_origin().InNanoseconds();
 }
 
-}  // namespace tracing
\ No newline at end of file
+}  // namespace tracing
