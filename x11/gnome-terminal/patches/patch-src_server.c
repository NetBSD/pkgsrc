$NetBSD: patch-src_server.c,v 1.2 2022/08/20 21:41:44 gutteridge Exp $

error: %m is only allowed in syslog(3) like functions [-Werror=format=]
https://gitlab.gnome.org/GNOME/gnome-terminal/-/commit/fd27fa449c8a494c41fcb0a8c127ffa74725b8be

--- src/server.c.orig	2020-03-05 21:43:41.000000000 +0000
+++ src/server.c
@@ -159,7 +159,7 @@ init_server (int argc,
   }
 
   if (!increase_rlimit_nofile ()) {
-    g_printerr ("Failed to increase RLIMIT_NOFILE: %m\n");
+    g_printerr ("Failed to increase RLIMIT_NOFILE: %s\n", strerror(errno));
   }
 
   /* Now we can create the app */
