$NetBSD: patch-lib_libxview_panel_p__select.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/panel/p_select.c.orig	2012-11-14 14:28:21.000000000 +0000
+++ lib/libxview/panel/p_select.c
@@ -357,7 +357,7 @@ panel_default_event(p_public, event, arg
 }
 
 
-Sv1_public
+Sv1_public void
 panel_handle_event(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -375,7 +375,7 @@ panel_handle_event(client_object, event)
 }
 
 
-Sv1_public
+Sv1_public void
 panel_begin_preview(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -390,7 +390,7 @@ panel_begin_preview(client_object, event
 }
 
 
-Sv1_public
+Sv1_public void
 panel_update_preview(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -405,7 +405,7 @@ panel_update_preview(client_object, even
 }
 
 
-Sv1_public
+Sv1_public void
 panel_accept_preview(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -434,7 +434,7 @@ panel_accept_preview(client_object, even
 }
 
 
-Sv1_public
+Sv1_public void
 panel_cancel_preview(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -456,7 +456,7 @@ panel_cancel_preview(client_object, even
 }
 
 
-Sv1_public
+Sv1_public void
 panel_accept_menu(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -480,7 +480,7 @@ panel_accept_menu(client_object, event)
 }
 
 
-Sv1_public
+Sv1_public void
 panel_accept_key(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
@@ -495,7 +495,7 @@ panel_accept_key(client_object, event)
 }
 
 
-Sv1_public
+Sv1_public void
 panel_cancel(client_object, event)
     Panel_item      client_object;	/* could be a Panel */
     Event          *event;
