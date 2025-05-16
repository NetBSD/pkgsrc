$NetBSD: patch-chromecast_media_base_default__monotonic__clock.cc,v 1.2 2025/05/16 16:08:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chromecast/media/base/default_monotonic_clock.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chromecast/media/base/default_monotonic_clock.cc
@@ -11,7 +11,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chromecast/media/base/buildflags.h"
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -28,7 +28,7 @@ std::unique_ptr<MonotonicClock> Monotoni
   return std::make_unique<DefaultMonotonicClock>();
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int64_t MonotonicClockNow() {
   timespec now = {0, 0};
 #if BUILDFLAG(MEDIA_CLOCK_MONOTONIC_RAW)
