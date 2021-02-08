$NetBSD: patch-mozilla_toolkit_components_terminator_nsTerminator.cpp,v 1.3 2021/02/08 12:26:20 ryoon Exp $

--- toolkit/components/terminator/nsTerminator.cpp.orig	2020-02-17 23:39:41.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -38,7 +38,7 @@
 #if defined(XP_WIN)
 #include <windows.h>
 #else
-#include <unistd.h>
+#include <time.h>
 #endif
 
 #include "mozilla/ArrayUtils.h"
@@ -149,7 +149,10 @@ RunWatchdog(void* arg)
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
