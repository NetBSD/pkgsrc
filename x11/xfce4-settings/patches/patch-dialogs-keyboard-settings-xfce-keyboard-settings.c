$NetBSD: patch-dialogs-keyboard-settings-xfce-keyboard-settings.c,v 1.1 2011/09/08 00:22:49 joerg Exp $

--- dialogs/keyboard-settings/xfce-keyboard-settings.c.orig	2011-09-07 12:45:30.000000000 +0000
+++ dialogs/keyboard-settings/xfce-keyboard-settings.c
@@ -1082,8 +1082,8 @@ xfce_keyboard_settings_update_sensitive 
   GtkWidget *xkb_layout_frame;
   gboolean   active;
 
-  g_return_if_fail (XFCE_IS_KEYBOARD_SETTINGS (settings));
-  g_return_if_fail (GLADE_IS_XML (settings->priv->glade_xml));
+  g_return_val_if_fail (XFCE_IS_KEYBOARD_SETTINGS (settings), FALSE);
+  g_return_val_if_fail (GLADE_IS_XML (settings->priv->glade_xml), FALSE);
 
   active = gtk_toggle_button_get_active (toggle);
   xkb_model_frame = glade_xml_get_widget (settings->priv->glade_xml, "xkb_model_frame");
