$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.2 2018/11/04 00:38:45 ryoon Exp $

* Fix segfault on exit under NetBSD

--- toolkit/components/terminator/nsTerminator.cpp.orig	2018-10-18 20:06:16.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -36,7 +36,7 @@
 #if defined(XP_WIN)
 #include <windows.h>
 #else
-#include <unistd.h>
+#include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -178,7 +178,10 @@ RunWatchdog(void* arg)
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
