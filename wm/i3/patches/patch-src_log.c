$NetBSD: patch-src_log.c,v 1.5 2017/08/09 11:13:30 nros Exp $
* NetBSD versions below and 7 miss shm_open and shm_unlink
* NetBSD versions below 8 miss pthread_condattr_pshared 
--- src/log.c.orig	2016-03-06 15:17:18.000000000 +0000
+++ src/log.c	2016-05-01 10:51:32.392955298 +0000
@@ -116,6 +116,7 @@
  *
  */
 void open_logbuffer(void) {
+#if !defined(__NetBSD__) 
     /* Reserve 1% of the RAM for the logfile, but at max 25 MiB.
          * For 512 MiB of RAM this will lead to a 5 MiB log buffer.
          * At the moment (2011-12-10), no testcase leads to an i3 log
@@ -166,6 +167,7 @@
     logwalk = logbuffer + sizeof(i3_shmlog_header);
     loglastwrap = logbuffer + logbuffer_size;
     store_log_markers();
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
@@ -173,11 +175,13 @@
  *
  */
 void close_logbuffer(void) {
+#if !defined(__NetBSD__)
     close(logbuffer_shm);
     shm_unlink(shmlogname);
     free(shmlogname);
     logbuffer = NULL;
     shmlogname = "";
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
