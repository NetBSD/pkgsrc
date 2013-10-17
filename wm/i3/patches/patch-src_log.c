$NetBSD: patch-src_log.c,v 1.2 2013/10/17 22:41:12 tonnerre Exp $

NetBSD does not support shm_open (3), disable the code in this case

--- src/log.c.orig	2013-08-07 18:50:24.000000000 +0000
+++ src/log.c	2013-10-06 16:45:34.000000000 +0000
@@ -108,6 +108,7 @@
          * For 512 MiB of RAM this will lead to a 5 MiB log buffer.
          * At the moment (2011-12-10), no testcase leads to an i3 log
          * of more than ~ 600 KiB. */
+#if !defined(__NetBSD__)
         long long physical_mem_bytes;
 #if defined(__APPLE__)
         int mib[2] = { CTL_HW, HW_MEMSIZE };
@@ -157,6 +158,7 @@
         logwalk = logbuffer + sizeof(i3_shmlog_header);
         loglastwrap = logbuffer + logbuffer_size;
         store_log_markers();
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
@@ -164,10 +166,12 @@
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
