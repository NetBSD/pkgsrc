$NetBSD: patch-toolkit_components_terminator_nsTerminator.cpp,v 1.1 2021/09/08 22:19:50 nia Exp $

* Fix segfault on exit under NetBSD

--- toolkit/components/terminator/nsTerminator.cpp.orig	2021-04-08 21:20:12.000000000 +0000
+++ toolkit/components/terminator/nsTerminator.cpp
@@ -37,7 +37,7 @@
 #if defined(XP_WIN)
 #  include <windows.h>
 #else
-#  include <unistd.h>
+#  include <time.h>
 #endif
 
 #include "mozilla/AppShutdown.h"
@@ -238,7 +238,10 @@ void RunWatchdog(void* arg) {
 #if defined(XP_WIN)
     Sleep(1000 /* ms */);
 #else
-    usleep(1000000 /* usec */);
+    struct timespec tickd;
+    tickd.tv_sec = 1;
+    tickd.tv_nsec = 0;
+    nanosleep(&tickd, NULL);
 #endif
 
     // If we are still alive then we just crash.
