$NetBSD: patch-src_main.c,v 1.1.1.1 2013/02/12 23:25:35 tonnerre Exp $

--- src/main.c.orig	2012-12-11 23:08:17.000000000 +0000
+++ src/main.c
@@ -218,12 +218,6 @@ static void i3_exit(void) {
 #if EV_VERSION_MAJOR >= 4
     ev_loop_destroy(main_loop);
 #endif
-
-    if (*shmlogname != '\0') {
-        fprintf(stderr, "Closing SHM log \"%s\"\n", shmlogname);
-        fflush(stderr);
-        shm_unlink(shmlogname);
-    }
 }
 
 /*
@@ -233,9 +227,6 @@ static void i3_exit(void) {
  *
  */
 static void handle_signal(int sig, siginfo_t *info, void *data) {
-    if (*shmlogname != '\0') {
-        shm_unlink(shmlogname);
-    }
     raise(sig);
 }
 
