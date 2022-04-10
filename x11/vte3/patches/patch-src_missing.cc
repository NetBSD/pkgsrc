$NetBSD: patch-src_missing.cc,v 1.1 2022/04/10 03:53:33 gutteridge Exp $

Fix basic file limit functionality on NetBSD.

--- src/missing.cc.orig	2022-03-27 17:52:19.000000000 +0000
+++ src/missing.cc
@@ -119,7 +119,7 @@ getrlimit_NOFILE_max(void)
 
 #endif /* HAVE_SYS_RESOURCE_H */
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__NetBSD__)
         /* Use sysconf() function provided by the system if it is known to be
          * async-signal safe.
          */
