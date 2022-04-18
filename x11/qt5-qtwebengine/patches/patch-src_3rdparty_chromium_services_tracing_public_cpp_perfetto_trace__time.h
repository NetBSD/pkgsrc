$NetBSD: patch-src_3rdparty_chromium_services_tracing_public_cpp_perfetto_trace__time.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/tracing/public/cpp/perfetto/trace_time.h
@@ -11,7 +11,7 @@
 namespace tracing {
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
-    defined(OS_FUCHSIA)
+    defined(OS_FUCHSIA) || defined(OS_BSD)
 // Linux, Android, and Fuchsia all use CLOCK_MONOTONIC. See crbug.com/166153
 // about efforts to unify base::TimeTicks across all platforms.
 constexpr perfetto::protos::pbzero::BuiltinClock kTraceClockId =
