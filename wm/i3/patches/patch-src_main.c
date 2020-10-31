$NetBSD: patch-src_main.c,v 1.7 2020/10/31 13:55:17 wiz Exp $

* NetBSD versions lower than 7 does not have shm_open and shm_unlink
  see patch-src_log.c 

--- src/main.c.orig	2019-08-03 13:14:38.000000000 +0000
+++ src/main.c
@@ -161,11 +161,13 @@ void main_set_x11_cb(bool enable) {
  *
  */
 static void i3_exit(void) {
+#if !defined(__NetBSD__)
     if (*shmlogname != '\0') {
         fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
         fflush(stderr);
         shm_unlink(shmlogname);
     }
+#endif
     ipc_shutdown(SHUTDOWN_REASON_EXIT, -1);
     unlink(config.ipc_socket_path);
     xcb_disconnect(conn);
@@ -189,9 +191,11 @@ static void i3_exit(void) {
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
 
