$NetBSD: patch-src_launcher_apps-common.c,v 1.1 2025/03/28 09:26:24 wiz Exp $

* Add applications path of pkgsrc

--- src/launcher/apps-common.c.orig	2025-02-05 09:47:18.883124706 +0000
+++ src/launcher/apps-common.c
@@ -317,6 +317,7 @@ const GSList *get_apps_locations()
     apps_locations = load_locations_from_env(apps_locations, "XDG_DATA_DIRS", "applications", NULL);
 
     apps_locations = g_slist_append(apps_locations, g_strdup("/usr/local/share/applications"));
+    apps_locations = g_slist_append(apps_locations, g_strdup("@PREFIX@/share/applications"));
     apps_locations = g_slist_append(apps_locations, g_strdup("/usr/share/applications"));
     apps_locations = g_slist_append(apps_locations, g_strdup("/opt/share/applications"));
 
