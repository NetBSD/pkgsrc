$NetBSD: patch-leapsecs__read.c,v 1.1 2021/10/30 09:14:05 schmonz Exp $

PKG_SYSCONFDIR support.

--- leapsecs_read.c.orig	1999-11-15 06:33:15.000000000 +0000
+++ leapsecs_read.c
@@ -18,7 +18,7 @@ int leapsecs_read()
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("@PKG_SYSCONFDIR@/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
