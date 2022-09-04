$NetBSD: patch-src_Toolbar.cc,v 1.2 2022/09/04 19:16:13 gutteridge Exp $

* Fix build failure when time_t is 64 bits on a 32-bit machine.
* Fix build with GCC 12 (missing <time.h> include)
https://github.com/bbidulock/blackboxwm/commit/adb18c673fae698bfdcf979349aaf665ef224035

--- src/Toolbar.cc.orig	2013-09-24 17:20:15.000000000 +0000
+++ src/Toolbar.cc
@@ -38,13 +38,16 @@
 #include <X11/Xutil.h>
 #include <sys/time.h>
 #include <assert.h>
+#include <time.h>
 
 
 long nextTimeout(int resolution)
 {
   timeval now;
+  int secs;
   gettimeofday(&now, 0);
-  return (std::max(1000l, ((((resolution - (now.tv_sec % resolution)) * 1000l))
+  secs = now.tv_sec % resolution;
+  return (std::max(1000l, ((((resolution - secs) * 1000l))
                            - (now.tv_usec / 1000l))));
 }
 
