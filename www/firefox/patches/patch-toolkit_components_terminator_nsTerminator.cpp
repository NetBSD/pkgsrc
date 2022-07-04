$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.7 2022/07/04 14:34:08 ryoon Exp $

* Fix segfault on exit under NetBSD

--- toolkit/components/terminator/nsTerminator.cpp.orig	2022-06-16 21:35:58.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -34,7 +34,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/AppShutdown.h"
@@ -184,7 +184,10 @@ void RunWatchdog(void* arg) {
 #if defined(XP_WIN)
     Sleep(HEARTBEAT_INTERVAL_MS /* ms */);
 #else
-    usleep(HEARTBEAT_INTERVAL_MS * 1000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = HEARTBEAT_INTERVAL_MS;
+    tickd.tv_nsec = 0;
+    nanosleep(&tickd, NULL);
 #endif
 
     if (gHeartbeat++ < timeToLive) {
