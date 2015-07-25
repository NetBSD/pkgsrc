$NetBSD: patch-src_main.c,v 1.1 2015/07/25 02:06:04 kamil Exp $

Add missing header for strspn(3).

Backport additional changes from Fedora.
http://pkgs.fedoraproject.org/cgit/gcolor2.git/tree/gcolor2-0.4-missing-includes.patch

--- src/main.c.orig	2005-07-11 14:55:49.000000000 +0000
+++ src/main.c
@@ -2,8 +2,11 @@
 #  include <config.h>
 #endif
 
+#include <glib/gprintf.h>
 #include <gtk/gtk.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 
 #include "interface.h"
 #include "support.h"
@@ -48,8 +51,6 @@ gchar* get_system_file ()
 
 void add_list_color (gchar *spec, gchar *name, gchar *type, gboolean is_new_color)
 {
-	GdkPixmap   *pixmap;
-	GdkBitmap   *mask;
 	GdkPixbuf   *buf;
 	GtkTreeIter  iter;
 	
@@ -103,7 +104,7 @@ void add_rgb_file (gchar *filename, gcha
 	gchar *name;
 	gchar  buffer[512];
 	gchar  spec[8];
-	gint   r, g, b, lr, lg, lb;
+	gint   r, g, b, lr = 0, lg = 0, lb = 0;
 	
 	fp = fopen (filename, "r");
 	if (!fp)
@@ -140,7 +141,6 @@ gint main (gint argc, gchar *argv[])
 	GtkTreeViewColumn *column;
 	GtkWidget         *treeview;
 	GtkTreeSelection  *select;
-	gchar             *buf;
 	
 #ifdef ENABLE_NLS
 	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
