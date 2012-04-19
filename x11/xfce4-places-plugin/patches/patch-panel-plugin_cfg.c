$NetBSD: patch-panel-plugin_cfg.c,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/cfg.c.orig	2012-04-19 14:12:44.000000000 +0000
+++ panel-plugin/cfg.c
@@ -37,31 +37,31 @@
 
 /********** PlacesCfgViewIface helpers **********/
 
-inline PlacesCfg*
+PlacesCfg*
 places_cfg_view_iface_get_cfg(PlacesCfgViewIface *iface)
 {
     return iface->cfg;
 }
 
-inline void
+void
 places_cfg_view_iface_open_dialog(PlacesCfgViewIface *iface)
 {
     iface->open_dialog(iface->cfg);
 }
 
-inline void
+void
 places_cfg_view_iface_load(PlacesCfgViewIface *iface)
 {
     iface->load(iface->cfg);
 }
 
-inline void
+void
 places_cfg_view_iface_save(PlacesCfgViewIface *iface)
 {
     iface->save(iface->cfg);
 }
 
-inline void
+void
 places_cfg_view_iface_finalize(PlacesCfgViewIface *iface)
 {
     iface->finalize(iface);
