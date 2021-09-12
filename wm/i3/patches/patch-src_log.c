$NetBSD: patch-src_log.c,v 1.9 2021/09/12 07:31:44 nia Exp $

- ftruncate() is unimplemented in NetBSD FFS.
- NetBSD lacks pthread_condattr_setpshared.

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
@@ -161,7 +161,7 @@ void open_logbuffer(void) {
 
     header = (i3_shmlog_header *)logbuffer;
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
     pthread_condattr_t cond_attr;
     pthread_condattr_init(&cond_attr);
     if (pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED) != 0)
