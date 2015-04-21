$NetBSD: patch-panel-plugin_model__volumes.c,v 1.1 2015/04/21 08:56:45 jperkin Exp $

Fix inline use.
--- panel-plugin/model_volumes.c.orig	2012-08-28 09:17:10.000000000 +0000
+++ panel-plugin/model_volumes.c
@@ -383,7 +383,7 @@ pbvol_is_present(GVolume *volume)
     return has_media && !is_shadowed;
 }
 
-static inline gboolean
+static gboolean
 pbvol_show_volume(GVolume *volume){
     GMount *mount = g_volume_get_mount(volume);
     DBG("Volume: %s [mounted=%x removable=%x present=%x]", g_volume_get_name(volume), 
