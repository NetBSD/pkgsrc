$NetBSD: patch-kdecore_io_kdirwatch__p.h,v 1.1 2015/01/31 22:52:56 jperkin Exp $

SunOS inotify requires sys/filio.h for FIONREAD

--- kdecore/io/kdirwatch_p.h.orig	2014-11-06 22:33:50.000000000 +0000
+++ kdecore/io/kdirwatch_p.h
@@ -52,6 +52,9 @@ class QSocketNotifier;
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/inotify.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 
 #ifndef IN_DONT_FOLLOW
 #define IN_DONT_FOLLOW 0x02000000
