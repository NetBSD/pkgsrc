$NetBSD: patch-src_html.c,v 1.1 2025/12/08 07:25:22 vins Exp $

pthread_tryjoin_np is a GNUism.
https://www.gnu.org/software/gnulib/manual/html_node/pthread_005ftryjoin_005fnp.html

--- src/html.c.orig	2025-11-09 16:04:36.000000000 +0000
+++ src/html.c
@@ -11,7 +11,7 @@ extern int gettimeofday(struct timeval *
 
 // OSX has no pthread_tryjoin_np, so we can't do our
 // asynchronous timers under OSX, which is really no great loss.
-#if defined(__APPLE__) || defined(__ANDROID__) || defined(__FreeBSD__)
+#if !defined(___GNU_SOURCE)
 #define pthread_tryjoin_np pthread_join
 #endif
 
