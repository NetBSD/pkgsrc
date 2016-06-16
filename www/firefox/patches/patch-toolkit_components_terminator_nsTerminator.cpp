$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.1 2016/06/16 12:08:21 ryoon Exp $

* Fix segfault on exit under NetBSD

--- toolkit/components/terminator/nsTerminator.cpp.orig	2016-06-15 21:54:53.514370128 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -36,7 +36,7 @@
 #if defined(XP_WIN)
 #include <windows.h>
 #else
-#include <unistd.h>
+#include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -147,7 +147,10 @@ RunWatchdog(void* arg)
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
