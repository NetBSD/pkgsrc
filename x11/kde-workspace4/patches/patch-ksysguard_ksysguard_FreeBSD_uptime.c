$NetBSD: patch-ksysguard_ksysguard_FreeBSD_uptime.c,v 1.1 2012/03/31 06:39:20 marino Exp $

--- ksysguard/ksysguardd/FreeBSD/uptime.c.orig	2012-03-30 22:35:19.995531000 +0000
+++ ksysguard/ksysguardd/FreeBSD/uptime.c
@@ -38,8 +38,10 @@ void printUptime( const char* cmd ) {
     struct timespec tp;
     float uptime = 0.;
 
+#if defined(CLOCK_UPTIME)
     if (clock_gettime(CLOCK_UPTIME, &tp) != -1)
         uptime = tp.tv_nsec / 1000000000.0 + tp.tv_sec;
+#endif
     fprintf( CurrentClient, "%f\n", uptime);
 }
 
