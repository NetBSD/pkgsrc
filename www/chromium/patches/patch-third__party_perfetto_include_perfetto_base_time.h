$NetBSD: patch-third__party_perfetto_include_perfetto_base_time.h,v 1.1 2025/02/06 09:58:27 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/base/time.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -199,6 +199,9 @@ inline TimeNanos GetTimeInternalNs(clock
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+  return GetTimeInternalNs(kWallTimeClockSource);
+#else
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -206,6 +209,7 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
@@ -213,7 +217,13 @@ inline TimeNanos GetWallTimeNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
+#if defined(__OpenBSD__) || defined(__NetBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC);
+#elif defined(__FreeBSD__)
+  return GetTimeInternalNs(CLOCK_MONOTONIC_FAST);
+#else
   return GetTimeInternalNs(CLOCK_MONOTONIC_RAW);
+#endif
 }
 
 inline TimeNanos GetThreadCPUTimeNs() {
