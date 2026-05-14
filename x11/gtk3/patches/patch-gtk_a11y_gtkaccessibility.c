$NetBSD: patch-gtk_a11y_gtkaccessibility.c,v 1.5 2026/05/14 17:42:34 ryoon Exp $

Make gtk3-atk-bridge an option to avoid unwanted dbus dependency.

--- gtk/a11y/gtkaccessibility.c.orig	2026-03-23 02:24:49.000000000 +0000
+++ gtk/a11y/gtkaccessibility.c
@@ -38,8 +38,10 @@
 #include <gtk/gtkaccessible.h>
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
 #include <atk-bridge.h>
 #endif
+#endif
 
 static gboolean gail_focus_watcher      (GSignalInvocationHint *ihint,
                                          guint                  n_param_values,
@@ -987,7 +989,9 @@ _gtk_accessibility_init (void)
   do_window_event_initialization ();
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_init (NULL, NULL);
+#endif
 #endif
 
   atk_misc_instance = g_object_new (GTK_TYPE_MISC_IMPL, NULL);
