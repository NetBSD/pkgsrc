$NetBSD: patch-gtk_gtkselection.c,v 1.1 2014/02/13 20:18:14 wiz Exp $

Add missing return value. Fixes compilation with clang.

--- gtk/gtkselection.c.orig	2014-01-27 22:40:26.000000000 +0000
+++ gtk/gtkselection.c
@@ -2294,7 +2294,7 @@ _gtk_selection_request (GtkWidget *widge
   gulong selection_max_size;
 
   if (event->requestor == NULL)
-    return;
+    return FALSE;
 
   if (initialize)
     gtk_selection_init ();
