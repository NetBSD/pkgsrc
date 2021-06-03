$NetBSD: patch-src_backends_x11_meta-input-settings-x11.c,v 1.1 2021/06/03 15:04:57 cirnatdan Exp $

Fix #ifdefs to avoid initialization error on non-Linux

--- src/backends/x11/meta-input-settings-x11.c.orig	2021-03-20 12:08:54.064907300 +0000
+++ src/backends/x11/meta-input-settings-x11.c
@@ -45,6 +45,7 @@ typedef struct _MetaInputSettingsX11Priv
 #ifdef HAVE_LIBGUDEV
   GUdevClient *udev_client;
 #endif
+  bool dummy_field; // struct needs at least one element to compile
 } MetaInputSettingsX11Private;
 
 G_DEFINE_TYPE_WITH_PRIVATE (MetaInputSettingsX11, meta_input_settings_x11,
@@ -765,11 +766,10 @@ meta_input_settings_x11_set_tablet_aspec
 static void
 meta_input_settings_x11_dispose (GObject *object)
 {
-#ifdef HAVE_LIBGUDEV
   MetaInputSettingsX11 *settings_x11 = META_INPUT_SETTINGS_X11 (object);
   MetaInputSettingsX11Private *priv =
     meta_input_settings_x11_get_instance_private (settings_x11);
-
+#ifdef HAVE_LIBGUDEV
   g_clear_object (&priv->udev_client);
 #endif
 
@@ -938,11 +938,10 @@ meta_input_settings_x11_class_init (Meta
 static void
 meta_input_settings_x11_init (MetaInputSettingsX11 *settings)
 {
-#ifdef HAVE_LIBGUDEV
   MetaInputSettingsX11Private *priv =
     meta_input_settings_x11_get_instance_private (settings);
   const char *subsystems[] = { NULL };
-
+#ifdef HAVE_LIBGUDEV
   priv->udev_client = g_udev_client_new (subsystems);
 #endif
 }
