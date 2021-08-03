$NetBSD: patch-src_3rdparty_chromium_third__party_perfetto_include_perfetto_base_time.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/time.h.orig	2020-06-25 09:34:47.000000000 +0000
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/base/time.h
@@ -141,6 +141,9 @@ inline TimeNanos GetTimeInternalNs(clock
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_NETBSD)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -148,6 +151,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
