$NetBSD: patch-mozilla_ipc_chromium_src_base_time__posix.cc,v 1.3 2013/01/07 21:55:30 ryoon Exp $

--- mozilla/ipc/chromium/src/base/time_posix.cc.orig	2012-11-18 10:19:38.000000000 +0000
+++ mozilla/ipc/chromium/src/base/time_posix.cc
@@ -167,7 +167,7 @@ TimeTicks TimeTicks::Now() {
   // With numer and denom = 1 (the expected case), the 64-bit absolute time
   // reported in nanoseconds is enough to last nearly 585 years.
 
-#elif defined(__OpenBSD__) || defined(OS_POSIX) && \
+#elif defined(OS_OPENBSD) || defined(OS_POSIX) && \
       defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0
 
   struct timespec ts;
