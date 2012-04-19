$NetBSD: patch-panel-plugin_view.h,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/view.h.orig	2012-04-19 14:11:58.000000000 +0000
+++ panel-plugin/view.h
@@ -44,16 +44,16 @@ typedef struct {
     
 } PlacesViewCfgIface;
 
-inline void
+void
 places_view_cfg_iface_update_menu(PlacesViewCfgIface*);
 
-inline void
+void
 places_view_cfg_iface_update_button(PlacesViewCfgIface*);
 
-inline void
+void
 places_view_cfg_iface_reconfigure_model(PlacesViewCfgIface*);
 
-inline GtkWidget*
+GtkWidget*
 places_view_cfg_iface_make_empty_cfg_dialog(PlacesViewCfgIface*);
 
 #include "cfg.h"
