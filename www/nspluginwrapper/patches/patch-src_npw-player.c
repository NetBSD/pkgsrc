$NetBSD: patch-src_npw-player.c,v 1.3 2016/10/15 15:18:01 tsutsui Exp $

- add and use proper pkgsrc libdir.

--- src/npw-player.c.orig	2011-07-01 03:18:57.000000000 +0000
+++ src/npw-player.c
@@ -2012,12 +2012,17 @@ get_plugin_dirs (void)
     }
 
   path = g_build_filename
-    (G_DIR_SEPARATOR_S "usr", "lib", "mozilla", "plugins", NULL);
+    (G_DIR_SEPARATOR_S LIBDIR, "mozilla", "plugins", NULL);
   dirs = g_list_prepend_if_path_exists (dirs, path);
   g_free (path);
 
   path = g_build_filename
-    (G_DIR_SEPARATOR_S "usr", "lib", "browser", "plugins", NULL);
+    (G_DIR_SEPARATOR_S LIBDIR, "browser", "plugins", NULL);
+  dirs = g_list_prepend_if_path_exists (dirs, path);
+  g_free (path);
+
+  path = g_build_filename
+    (G_DIR_SEPARATOR_S LIBDIR, "netscape", "plugins", NULL);
   dirs = g_list_prepend_if_path_exists (dirs, path);
   g_free (path);
 
