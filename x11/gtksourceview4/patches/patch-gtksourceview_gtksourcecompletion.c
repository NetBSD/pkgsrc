$NetBSD: patch-gtksourceview_gtksourcecompletion.c,v 1.1 2020/04/26 16:15:34 wiz Exp $

https://gitlab.gnome.org/GNOME/gtksourceview/-/commit/cfe7e0a1c5d4940172fcc0f54ea073f4425e7f1c

--- gtksourceview/gtksourcecompletion.c.orig	2020-03-06 22:36:55.771244500 +0000
+++ gtksourceview/gtksourcecompletion.c
@@ -2720,6 +2720,8 @@ gtk_source_completion_class_init (GtkSou
 				      2,
 				      GTK_TYPE_SCROLL_STEP, GTK_SCROLL_ENDS,
 				      G_TYPE_INT, 1);
+
+	g_type_ensure (GTK_SOURCE_TYPE_COMPLETION_INFO);
 }
 
 static void
