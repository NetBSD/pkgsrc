$NetBSD: patch-panel-plugin_cfg.h,v 1.1 2012/04/19 21:12:42 joerg Exp $

--- panel-plugin/cfg.h.orig	2012-04-19 14:12:42.000000000 +0000
+++ panel-plugin/cfg.h
@@ -62,19 +62,19 @@ struct _PlacesCfgViewIface {
     
 };
 
-inline PlacesCfg*
+PlacesCfg*
 places_cfg_view_iface_get_cfg(PlacesCfgViewIface*);
 
-inline void
+void
 places_cfg_view_iface_open_dialog(PlacesCfgViewIface*);
 
-inline void
+void
 places_cfg_view_iface_load(PlacesCfgViewIface*);
 
-inline void
+void
 places_cfg_view_iface_save(PlacesCfgViewIface*);
 
-inline void
+void
 places_cfg_view_iface_finalize(PlacesCfgViewIface*);
 
 
