$NetBSD: patch-src_log.c,v 1.3 2014/08/09 19:14:01 degroote Exp $

NetBSD does not support shm_open (3), disable the code in this case

--- src/log.c.orig	2014-06-15 17:12:43.000000000 +0000
+++ src/log.c	2014-08-09 20:52:23.000000000 +0000
@@ -108,6 +108,7 @@
          * For 512 MiB of RAM this will lead to a 5 MiB log buffer.
          * At the moment (2011-12-10), no testcase leads to an i3 log
          * of more than ~ 600 KiB. */
+#if !defined(__NetBSD__)
     long long physical_mem_bytes;
 #if defined(__APPLE__)
     int mib[2] = {CTL_HW, HW_MEMSIZE};
@@ -163,6 +164,7 @@
     logwalk = logbuffer + sizeof(i3_shmlog_header);
     loglastwrap = logbuffer + logbuffer_size;
     store_log_markers();
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
@@ -170,10 +172,12 @@
  *
  */
 void close_logbuffer(void) {
+#if !defined(__NetBSD__)
     close(logbuffer_shm);
     shm_unlink(shmlogname);
     logbuffer = NULL;
     shmlogname = "";
+#endif
 }
 
 /*
