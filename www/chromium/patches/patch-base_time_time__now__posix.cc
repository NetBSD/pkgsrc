$NetBSD: patch-base_time_time__now__posix.cc,v 1.1 2025/05/16 16:08:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/time/time_now_posix.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ base/time/time_now_posix.cc
@@ -27,7 +27,7 @@
 #endif
 
 // NaCl doesn't support CLOCK_MONOTONIC_COARSE.
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC
 #else
 #define TIMETICKS_LOW_RESOLUTION_CLOCK CLOCK_MONOTONIC_COARSE
