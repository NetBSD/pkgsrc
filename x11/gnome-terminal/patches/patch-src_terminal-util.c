$NetBSD: patch-src_terminal-util.c,v 1.1 2020/06/20 15:05:48 nia Exp $

error: %m is only allowed in syslog(3) like functions [-Werror=format=]

--- src/terminal-util.c.orig	2020-03-05 22:09:14.000000000 +0000
+++ src/terminal-util.c
@@ -1286,7 +1286,7 @@ ensure_cache_dir (void)
   errno = 0;
   r = g_mkdir_with_parents (cache_dir, 0700);
   if (r == -1 && errno != EEXIST)
-    g_printerr ("Failed to create cache dir: %m\n");
+    g_printerr ("Failed to create cache dir: %s\n", strerror(errno));
   return r == 0;
 }
 
