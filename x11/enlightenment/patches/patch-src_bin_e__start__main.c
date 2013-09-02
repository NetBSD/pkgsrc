$NetBSD: patch-src_bin_e__start__main.c,v 1.1 2013/09/02 11:08:16 obache Exp $

* treat DragonFly same as other BSDs

--- src/bin/e_start_main.c.orig	2013-04-04 19:44:46.000000000 +0000
+++ src/bin/e_start_main.c
@@ -245,6 +245,7 @@ main(int argc, char **argv)
    Eina_Bool really_know = EINA_FALSE;
    struct sigaction action;
 #if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && \
+   !defined(__DragonFly__) && \
    !(defined (__MACH__) && defined (__APPLE__))
    Eina_Bool restart = EINA_TRUE;
 #endif
@@ -408,6 +409,7 @@ main(int argc, char **argv)
      really_know = EINA_TRUE;
 
 #if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__FreeBSD__) || \
+   defined(__DragonFly__) || \
    (defined (__MACH__) && defined (__APPLE__))
    execv(args[0], args);
 #endif
@@ -415,6 +417,7 @@ main(int argc, char **argv)
    /* not run at the moment !! */
 
 #if !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && \
+   !defined(__DragonFly__) && \
    !(defined (__MACH__) && defined (__APPLE__))
    /* Now looping until */
    while (restart)
