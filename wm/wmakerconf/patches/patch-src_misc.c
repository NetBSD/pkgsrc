$NetBSD: patch-src_misc.c,v 1.1 2019/12/15 08:02:50 gutteridge Exp $

Avoid deprecated glib2 functions that now cause errors.

--- src/misc.c.orig	2004-12-05 01:49:32.000000000 +0000
+++ src/misc.c
@@ -482,9 +482,9 @@ copy_file (const char *dst, const char *
       if (dir)				/* directory is destination */
       {
 	 closedir (dir);
-	 if (streq (dst, g_dirname (src)))
+	 if (streq (dst, g_path_get_dirname (src)))
 	    return 0;
-	 dst_name = g_strconcat (dst, "/", g_basename (src), NULL);
+	 dst_name = g_strconcat (dst, "/", g_path_get_basename (src), NULL);
       }
       else
 	 dst_name = g_strdup (dst);
