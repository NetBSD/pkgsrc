$NetBSD: patch-src_launcher_icon-theme-common.c,v 1.1 2025/03/28 09:26:24 wiz Exp $

* Add icons path of pkgsrc, fix env based pathes

--- src/launcher/icon-theme-common.c.orig	2025-02-05 09:47:41.534572814 +0000
+++ src/launcher/icon-theme-common.c
@@ -55,15 +55,17 @@ const GSList *get_icon_locations()
     if (icon_locations)
         return icon_locations;
 
-    icon_locations = load_locations_from_env(icon_locations, "XDG_DATA_HOME", ".icons", NULL);
+    icon_locations = load_locations_from_env(icon_locations, "XDG_DATA_HOME", "icons", NULL);
 
     icon_locations = g_slist_append(icon_locations, g_build_filename(g_get_home_dir(), ".icons", NULL));
     icon_locations = g_slist_append(icon_locations, g_build_filename(g_get_home_dir(), ".local/share/icons", NULL));
 
-    icon_locations = load_locations_from_env(icon_locations, "XDG_DATA_DIRS", ".icons", ".pixmaps", NULL);
+    icon_locations = load_locations_from_env(icon_locations, "XDG_DATA_DIRS", "icons", "pixmaps", NULL);
 
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/local/share/icons"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/local/share/pixmaps"));
+    icon_locations = g_slist_append(icon_locations, g_strdup("@PREFIX@/share/icons"));
+    icon_locations = g_slist_append(icon_locations, g_strdup("@PREFIX@/share/pixmaps"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/share/icons"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/usr/share/pixmaps"));
     icon_locations = g_slist_append(icon_locations, g_strdup("/opt/share/icons"));
