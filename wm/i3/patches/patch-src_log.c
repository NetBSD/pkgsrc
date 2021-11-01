$NetBSD: patch-src_log.c,v 1.10 2021/11/01 20:42:58 wiz Exp $

- ftruncate() is unimplemented in NetBSD FFS.

--- src/log.c.orig	2021-02-27 09:37:58.756645200 +0000
+++ src/log.c
@@ -136,7 +136,7 @@ void open_logbuffer(void) {
         return;
     }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__APPLE__)
     if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
         fprintf(stderr, "Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
 #else
