$NetBSD: patch-src_log.c,v 1.6 2019/08/16 10:59:55 wiz Exp $
* NetBSD versions below and 7 miss shm_open and shm_unlink
* NetBSD versions below 8 miss pthread_condattr_pshared 
--- src/log.c.orig	2019-08-03 13:14:38.000000000 +0000
+++ src/log.c
@@ -123,6 +123,7 @@ void init_logging(void) {
  *
  */
 void open_logbuffer(void) {
+#if !defined(__NetBSD__) 
     /* Reserve 1% of the RAM for the logfile, but at max 25 MiB.
      * For 512 MiB of RAM this will lead to a 5 MiB log buffer.
      * At the moment (2011-12-10), no testcase leads to an i3 log
@@ -175,6 +176,7 @@ void open_logbuffer(void) {
     logwalk = logbuffer + sizeof(i3_shmlog_header);
     loglastwrap = logbuffer + logbuffer_size;
     store_log_markers();
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
@@ -182,11 +184,13 @@ void open_logbuffer(void) {
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
