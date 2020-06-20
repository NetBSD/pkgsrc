$NetBSD: patch-src_server.c,v 1.1 2020/06/20 15:05:48 nia Exp $

error: %m is only allowed in syslog(3) like functions [-Werror=format=]

--- src/server.c.orig	2020-03-05 21:43:41.000000000 +0000
+++ src/server.c
@@ -159,7 +159,7 @@ init_server (int argc,
   }
 
   if (!increase_rlimit_nofile ()) {
-    g_printerr ("Failed to increase RLIMIT_NOFILE: %m\n");
+    g_printerr ("Failed to increase RLIMIT_NOFILE: %s\n", strerror(errno));
   }
 
   /* Now we can create the app */
