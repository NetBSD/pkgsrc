$NetBSD: patch-panel-plugin_view.c,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/view.c.orig	2012-04-19 14:12:11.000000000 +0000
+++ panel-plugin/view.c
@@ -121,25 +121,25 @@ static void     pview_button_update(Plac
 
 /********** Interface for Cfg's Use **********/
 
-inline void
+void
 places_view_cfg_iface_update_menu(PlacesViewCfgIface *iface)
 {
     iface->update_menu(iface->places_view);
 }
 
-inline void
+void
 places_view_cfg_iface_update_button(PlacesViewCfgIface *iface)
 {
     iface->update_button(iface->places_view);
 }
 
-inline void
+void
 places_view_cfg_iface_reconfigure_model(PlacesViewCfgIface *iface)
 {
     iface->reconfigure_model(iface->places_view);
 }
 
-inline GtkWidget*
+GtkWidget*
 places_view_cfg_iface_make_empty_cfg_dialog(PlacesViewCfgIface *iface)
 {
     return iface->make_empty_cfg_dialog(iface->places_view);
