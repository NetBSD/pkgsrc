$NetBSD: patch-mozilla-release_toolkit_components_terminator_nsTerminator.cpp,v 1.1 2019/04/19 14:02:03 fox Exp $

* Fix segfault on exit under NetBSD

Original patch from ryoon, imported from www/firefox

--- mozilla-release/toolkit/components/terminator/nsTerminator.cpp.orig	2018-11-16 08:40:07.000000000 +0000
+++ mozilla-release/toolkit/components/terminator/nsTerminator.cpp
@@ -36,7 +36,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -170,7 +170,10 @@ void RunWatchdog(void* arg) {
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
