$NetBSD: patch-src_main.c,v 1.4 2018/10/19 15:21:54 jperkin Exp $
* NetBSD versions lower than 7 does not have shm_open and shm_unlink
  see patch-src_log.c 
--- src/main.c.orig	2018-03-10 17:29:14.000000000 +0000
+++ src/main.c
@@ -169,11 +169,13 @@ static void i3_exit(void) {
     ev_loop_destroy(main_loop);
 #endif
 
+#if !defined(__NetBSD__)
     if (*shmlogname != '\0') {
         fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
         fflush(stderr);
         shm_unlink(shmlogname);
     }
+#endif
     ipc_shutdown(SHUTDOWN_REASON_EXIT);
     unlink(config.ipc_socket_path);
 }
@@ -185,9 +187,11 @@ static void i3_exit(void) {
  *
  */
 static void handle_core_signal(int sig, siginfo_t *info, void *data) {
+#if !defined(__NetBSD__)
     if (*shmlogname != '\0') {
         shm_unlink(shmlogname);
     }
+#endif
     raise(sig);
 }
 
