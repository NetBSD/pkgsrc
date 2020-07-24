$NetBSD: patch-mozilla-release_toolkit_components_terminator_nsTerminator.cpp,v 1.2 2020/07/24 07:29:32 fox Exp $

* Fix segfault on exit under NetBSD

Taken from www/firefox

--- mozilla-release/toolkit/components/terminator/nsTerminator.cpp.orig	2020-05-21 22:38:09.000000000 +0000
+++ mozilla-release/toolkit/components/terminator/nsTerminator.cpp
@@ -36,7 +36,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -180,7 +180,10 @@ void RunWatchdog(void* arg) {
 #if defined(XP_WIN)
     Sleep(1000 /* ms */);
 #else
-    usleep(1000000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = 1;
+    tickd.tv_nsec = 0;
+    nanosleep(&tickd, NULL);
 #endif
     if (gHeartbeat++ < timeToLive) {
 #if !defined(MOZ_VALGRIND) || !defined(MOZ_CODE_COVERAGE)
