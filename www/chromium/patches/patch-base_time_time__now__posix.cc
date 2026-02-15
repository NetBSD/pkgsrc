$NetBSD: patch-base_time_time__now__posix.cc,v 1.14 2026/02/15 09:03:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/time/time_now_posix.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
 
