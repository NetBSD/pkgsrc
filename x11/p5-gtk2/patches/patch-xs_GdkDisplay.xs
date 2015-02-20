$NetBSD: patch-xs_GdkDisplay.xs,v 1.1 2015/02/20 14:52:34 wiz Exp $

Fix incorrect memory management, from upstream.
https://git.gnome.org/browse/perl-Gtk2/commit/?id=4856da628ce37099b27b66a88141dc6daad693b0

--- xs/GdkDisplay.xs.orig	2011-11-27 07:57:26.000000000 +0000
+++ xs/GdkDisplay.xs
@@ -69,7 +69,6 @@ gdk_display_list_devices (display)
 	devices = gdk_display_list_devices (display);
 	for (i = devices ; i != NULL ; i = i->next)
 		XPUSHs (sv_2mortal (newSVGdkDevice (i->data)));
-	g_list_free (devices);
 	
 
 GdkEvent* gdk_display_get_event (GdkDisplay *display) 
