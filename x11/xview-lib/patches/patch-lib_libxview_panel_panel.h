$NetBSD: patch-lib_libxview_panel_panel.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/panel/panel.h.orig	1993-06-29 05:17:02.000000000 +0000
+++ lib/libxview/panel/panel.h
@@ -703,19 +703,19 @@ EXTERN_FUNCTION (void		panel_show_focus_
 /*
  * event mapping routines 
  */
-EXTERN_FUNCTION (int panel_handle_event, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_handle_event, (Panel_item item, Event *event));
 EXTERN_FUNCTION (void panel_default_handle_event, (Panel_item item, Event *event));
-EXTERN_FUNCTION (int panel_cancel, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_cancel, (Panel_item item, Event *event));
 
 /*
  * Panel_item action routines 
  */
-EXTERN_FUNCTION (int panel_begin_preview, (Panel_item item, Event * event));
-EXTERN_FUNCTION (int panel_update_preview, (Panel_item item, Event *event));
-EXTERN_FUNCTION (int panel_accept_preview, (Panel_item item, Event *event));
-EXTERN_FUNCTION (int panel_cancel_preview, (Panel_item item, Event *event));
-EXTERN_FUNCTION (int panel_accept_menu, (Panel_item item, Event *event));
-EXTERN_FUNCTION (int panel_accept_key, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_begin_preview, (Panel_item item, Event * event));
+EXTERN_FUNCTION (void panel_update_preview, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_accept_preview, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_cancel_preview, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_accept_menu, (Panel_item item, Event *event));
+EXTERN_FUNCTION (void panel_accept_key, (Panel_item item, Event *event));
 
 /*
  * utilities 
