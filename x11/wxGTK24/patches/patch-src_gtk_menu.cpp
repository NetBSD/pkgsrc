$NetBSD: patch-src_gtk_menu.cpp,v 1.1 2012/02/16 20:26:18 hans Exp $

--- src/gtk/menu.cpp.orig	2003-09-21 13:31:57.000000000 +0200
+++ src/gtk/menu.cpp	2012-01-15 17:43:10.375045952 +0100
@@ -30,13 +30,13 @@
 #ifdef __WXGTK20__
     #include <glib-object.h>
 
-    #define gtk_accel_group_attach(g, o) _gtk_accel_group_attach((g), (o))
-    #define gtk_accel_group_detach(g, o) _gtk_accel_group_detach((g), (o))
+    #define gtk_accel_group_attach(g, o) gtk_window_add_accel_group((o), (g))
+    #define gtk_accel_group_detach(g, o) gtk_window_remove_accel_group((o), (g))
     #define gtk_menu_ensure_uline_accel_group(m) gtk_menu_get_accel_group(m)
 
-    #define ACCEL_OBJECT        GObject
+    #define ACCEL_OBJECT        GtkWindow
     #define ACCEL_OBJECTS(a)    (a)->acceleratables
-    #define ACCEL_OBJ_CAST(obj) G_OBJECT(obj)
+    #define ACCEL_OBJ_CAST(obj) GTK_WINDOW(obj)
 #else // GTK+ 1.x
     #define ACCEL_OBJECT        GtkObject
     #define ACCEL_OBJECTS(a)    (a)->attach_objects
