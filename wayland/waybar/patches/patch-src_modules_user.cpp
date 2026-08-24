$NetBSD: patch-src_modules_user.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Portable uptime usage, fallback to CLOCK_MONOTONIC

--- src/modules/user.cpp.orig	2025-12-18 09:12:40.964198952 +0000
+++ src/modules/user.cpp
@@ -63,10 +63,12 @@ long User::uptime_as_seconds() {
 #if HAVE_CPU_BSD
   struct timespec s_info;
   int flags = 0;
-#ifndef __OpenBSD__
+#ifdef CLOCK_UPTIME_PRECISE
   flags = CLOCK_UPTIME_PRECISE;
-#else
+#elif defined(CLOCK_UPTIME)
   flags = CLOCK_UPTIME;
+#else
+  flags = CLOCK_MONOTONIC;
 #endif
   if (0 == clock_gettime(flags, &s_info)) {
     uptime = s_info.tv_sec;
