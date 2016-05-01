--- src/main.c.orig	2016-05-01 10:53:25.236039259 +0000
+++ src/main.c	2016-05-01 10:54:26.269651048 +0000
@@ -166,11 +166,13 @@
     ev_loop_destroy(main_loop);
 #endif
 
+#if !defined(__NetBSD__)
     if (*shmlogname != '\0') {
         fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
         fflush(stderr);
         shm_unlink(shmlogname);
     }
+#endif /* !defined(__NetBSD__) */
 }
 
 /*
@@ -180,9 +182,11 @@
  *
  */
 static void handle_signal(int sig, siginfo_t *info, void *data) {
+#if !defined(__NetBSD__)
     if (*shmlogname != '\0') {
         shm_unlink(shmlogname);
     }
+#endif /* !defined(__NetBSD__) */
     raise(sig);
 }
 
