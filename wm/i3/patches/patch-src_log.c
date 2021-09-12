$NetBSD: patch-src_log.c,v 1.8 2021/09/12 07:22:47 nia Exp $

NetBSD lacks pthread_condattr_setpshared.

--- src/log.c.orig	2021-02-27 09:37:58.756645200 +0000
+++ src/log.c
@@ -161,7 +161,7 @@ void open_logbuffer(void) {
 
     header = (i3_shmlog_header *)logbuffer;
 
-#if !defined(__OpenBSD__)
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
     pthread_condattr_t cond_attr;
     pthread_condattr_init(&cond_attr);
     if (pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED) != 0)
