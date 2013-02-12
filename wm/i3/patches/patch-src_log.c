$NetBSD: patch-src_log.c,v 1.1.1.1 2013/02/12 23:25:35 tonnerre Exp $

--- src/log.c.orig	2012-12-11 23:08:17.000000000 +0000
+++ src/log.c
@@ -108,42 +108,7 @@ void init_logging(void) {
 #endif
         logbuffer_size = min(physical_mem_bytes * 0.01, shmlog_size);
         sasprintf(&shmlogname, "/i3-log-%d", getpid());
-        logbuffer_shm = shm_open(shmlogname, O_RDWR | O_CREAT, S_IREAD | S_IWRITE);
-        if (logbuffer_shm == -1) {
-            ELOG("Could not shm_open SHM segment for the i3 log: %s\n", strerror(errno));
-            return;
-        }
-
-        if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
-            close(logbuffer_shm);
-            shm_unlink("/i3-log-");
-            ELOG("Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
-            return;
-        }
-
-        logbuffer = mmap(NULL, logbuffer_size, PROT_READ | PROT_WRITE, MAP_SHARED, logbuffer_shm, 0);
-        if (logbuffer == MAP_FAILED) {
-            close(logbuffer_shm);
-            shm_unlink("/i3-log-");
-            ELOG("Could not mmap SHM segment for the i3 log: %s\n", strerror(errno));
-            logbuffer = NULL;
-            return;
-        }
-
-        /* Initialize with 0-bytes, just to be sure… */
-        memset(logbuffer, '\0', logbuffer_size);
-
-        header = (i3_shmlog_header*)logbuffer;
-
-        pthread_condattr_t cond_attr;
-        pthread_condattr_init(&cond_attr);
-        if (pthread_condattr_setpshared(&cond_attr, PTHREAD_PROCESS_SHARED) != 0)
-            ELOG("pthread_condattr_setpshared() failed, i3-dump-log -f will not work!\n");
-        pthread_cond_init(&(header->condvar), &cond_attr);
-
-        logwalk = logbuffer + sizeof(i3_shmlog_header);
-        loglastwrap = logbuffer + logbuffer_size;
-        store_log_markers();
+        return;
     }
     atexit(purge_zerobyte_logfile);
 }
