$NetBSD: patch-libgnomekbd_gkbd-keyboard-config.c,v 1.1 2019/12/22 22:30:58 joerg Exp $

g_strv_equal exists in newer glib.

--- libgnomekbd/gkbd-keyboard-config.c.orig	2019-12-22 18:05:27.205201216 +0000
+++ libgnomekbd/gkbd-keyboard-config.c
@@ -51,6 +51,7 @@ const gchar *GKBD_KEYBOARD_CONFIG_ACTIVE
  * static common functions
  */
 
+#if 0
 static gboolean
 g_strv_equal (gchar ** l1, gchar ** l2)
 {
@@ -75,6 +76,7 @@ g_strv_equal (gchar ** l1, gchar ** l2)
 	}
 	return (*l1 == NULL) && (*l2 == NULL);
 }
+#endif
 
 gboolean
 gkbd_keyboard_config_get_lv_descriptions (XklConfigRegistry *
