$NetBSD: patch-src_interface.c,v 1.1 2015/07/25 02:06:04 kamil Exp $

gdk_pixbuf_unref() is deprecated and replaced with g_object_unref()

--- src/interface.c.orig	2005-07-11 14:30:33.000000000 +0000
+++ src/interface.c
@@ -63,7 +63,7 @@ create_gcolor2 (void)
   if (gcolor2_icon_pixbuf)
     {
       gtk_window_set_icon (GTK_WINDOW (gcolor2), gcolor2_icon_pixbuf);
-      gdk_pixbuf_unref (gcolor2_icon_pixbuf);
+      g_object_unref (gcolor2_icon_pixbuf);
     }
 
   vbox1 = gtk_vbox_new (FALSE, 3);
@@ -242,7 +242,7 @@ create_save_dialog (void)
   if (save_dialog_icon_pixbuf)
     {
       gtk_window_set_icon (GTK_WINDOW (save_dialog), save_dialog_icon_pixbuf);
-      gdk_pixbuf_unref (save_dialog_icon_pixbuf);
+      g_object_unref (save_dialog_icon_pixbuf);
     }
   gtk_window_set_type_hint (GTK_WINDOW (save_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);
 
@@ -370,7 +370,7 @@ create_about_dialog (void)
   if (about_dialog_icon_pixbuf)
     {
       gtk_window_set_icon (GTK_WINDOW (about_dialog), about_dialog_icon_pixbuf);
-      gdk_pixbuf_unref (about_dialog_icon_pixbuf);
+      g_object_unref (about_dialog_icon_pixbuf);
     }
 
   dialog_vbox3 = GTK_DIALOG (about_dialog)->vbox;
@@ -487,7 +487,7 @@ create_delete_dialog (void)
   if (delete_dialog_icon_pixbuf)
     {
       gtk_window_set_icon (GTK_WINDOW (delete_dialog), delete_dialog_icon_pixbuf);
-      gdk_pixbuf_unref (delete_dialog_icon_pixbuf);
+      g_object_unref (delete_dialog_icon_pixbuf);
     }
   gtk_window_set_type_hint (GTK_WINDOW (delete_dialog), GDK_WINDOW_TYPE_HINT_DIALOG);
 
@@ -526,4 +526,3 @@ create_delete_dialog (void)
   gtk_widget_grab_default (delete_cancel);
   return delete_dialog;
 }
-
