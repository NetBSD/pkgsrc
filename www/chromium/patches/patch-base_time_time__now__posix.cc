$NetBSD: patch-base_time_time__now__posix.cc,v 1.31 2026/11/08 15:38:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/time/time_now_posix.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ base/time/time_now_posix.cc
@@ -110,7 +110,11 @@ std::optional<TimeTicks> MaybeTimeTicksN
 }
 
 TimeTicks TimeTicksLowResolutionNowIgnoringOverride() {
+#if BUILDFLAG(IS_BSD)
+  return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC));
+#else
   return TimeTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC_COARSE));
+#endif
 }
 }  // namespace subtle
 
@@ -147,7 +151,11 @@ namespace subtle {
 // ChromeOS, and Android). Apple platforms use an alternate implementation in
 // time_apple.mm.
 time_internal::RealTicks RealTicksNowIgnoringOverride() {
+#if BUILDFLAG(IS_NETBSD)
+  return time_internal::RealTicks() + Microseconds(ClockNow(CLOCK_MONOTONIC));
+#else
   return time_internal::RealTicks() + Microseconds(ClockNow(CLOCK_BOOTTIME));
+#endif
 }
 }  // namespace subtle
 
