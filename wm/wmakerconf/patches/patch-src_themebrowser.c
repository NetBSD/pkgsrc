$NetBSD: patch-src_themebrowser.c,v 1.2 2019/12/15 08:02:50 gutteridge Exp $

Fix build with WindowMaker 0.95.4 and change hard coded path name.
Also avoid deprecated glib2 functions that now cause errors.

--- src/themebrowser.c.orig	2005-02-25 23:37:44.000000000 +0000
+++ src/themebrowser.c
@@ -2705,7 +2705,7 @@ save_theme_backend (GtkWidget *widget, g
 	 oldfiles = g_list_remove (oldfiles, tmp);
 	 Free (tmp);
       }
-      if (!WMWritePropListToFile (theme, stylename, YES))
+      if (!WMWritePropListToFile (theme, stylename))
       {
 	 dialog_popup (DIALOG_ERROR, NULL, NULL,
 		       _("Can't save theme file\n`%s'\n"
@@ -3532,11 +3532,11 @@ compute_preview (GtkWidget *progress_bar
 
    if (!path)
    {
-      DIR *dir = opendir (g_dirname (pname));
+      DIR *dir = opendir (g_path_get_dirname (pname));
 
       if (!dir)				/* Make ~/.wmakerconf directory */
       {
-	 if (make_directory (g_dirname (pname)))
+	 if (make_directory (g_path_get_dirname (pname)))
 	 {
 	    Free (pname);
 	    return;
