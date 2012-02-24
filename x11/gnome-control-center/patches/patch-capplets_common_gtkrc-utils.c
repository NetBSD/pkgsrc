$NetBSD: patch-capplets_common_gtkrc-utils.c,v 1.1 2012/02/24 19:11:44 drochner Exp $

g_open is not a synonym for open and takes 3 arguments.

--- capplets/common/gtkrc-utils.c.orig	2010-11-18 09:05:08.000000000 +0000
+++ capplets/common/gtkrc-utils.c
@@ -105,7 +105,7 @@ gtkrc_get_details (gchar *filename, GSLi
 
 		read_files = g_slist_prepend (read_files, filename);
 
-		file = g_open (filename, O_RDONLY);
+		file = g_open (filename, O_RDONLY, 0);
 		if (file == -1)
 		{
 			g_warning ("Could not open file \"%s\"", filename);
@@ -200,7 +200,7 @@ gtkrc_get_color_scheme (const gchar *gtk
 
 		read_files = g_slist_prepend (read_files, filename);
 
-		file = g_open (filename, O_RDONLY);
+		file = g_open (filename, O_RDONLY, 0);
 		if (file == -1)
 		{
 			g_warning ("Could not open file \"%s\"", filename);
