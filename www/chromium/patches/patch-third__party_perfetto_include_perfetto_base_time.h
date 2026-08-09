$NetBSD: patch-third__party_perfetto_include_perfetto_base_time.h,v 1.24 2026/08/09 06:31:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/include/perfetto/base/time.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/perfetto/include/perfetto/base/time.h
@@ -280,6 +280,7 @@ inline TimeNanos GetTimeInternalNs(clock
 // Return ns from boot. Conversely to GetWallTimeNs, this clock counts also time
 // during suspend (when supported).
 inline TimeNanos GetBootTimeNs() {
+#ifdef CLOCK_BOOTTIME
   // Determine if CLOCK_BOOTTIME is available on the first call.
   static const clockid_t kBootTimeClockSource = [] {
     struct timespec ts = {};
@@ -287,6 +288,9 @@ inline TimeNanos GetBootTimeNs() {
     return res == 0 ? CLOCK_BOOTTIME : kWallTimeClockSource;
   }();
   return GetTimeInternalNs(kBootTimeClockSource);
+#else
+  return GetTimeInternalNs(kWallTimeClockSource);
+#endif
 }
 
 inline TimeNanos GetWallTimeNs() {
@@ -294,7 +298,7 @@ inline TimeNanos GetWallTimeNs() {
 }
 
 inline TimeNanos GetWallTimeRawNs() {
-#if (PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD))
+#if PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   // Note: CLOCK_MONOTONIC_RAW is a Linux extension.
   // FreeBSD doesn't implement it and its CLOCK_MONOTONIC_FAST
   // doesnt implement the same semantics as CLOCK_MONOTONIC_RAW.
