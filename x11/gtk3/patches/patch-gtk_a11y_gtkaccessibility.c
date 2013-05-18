$NetBSD: patch-gtk_a11y_gtkaccessibility.c,v 1.1 2013/05/18 22:44:43 prlw1 Exp $

gtk3-atk-bridge option to avoid dbus dependency.

--- gtk/a11y/gtkaccessibility.c.orig	2013-03-09 20:03:17.000000000 +0000
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
@@ -990,8 +992,10 @@ _gtk_accessibility_shutdown (void)
   g_clear_object (&atk_misc_instance);
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_cleanup ();
 #endif
+#endif
 
   undo_window_event_initialization ();
 }
@@ -1012,8 +1016,10 @@ _gtk_accessibility_init (void)
   do_window_event_initialization ();
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_init (NULL, NULL);
 #endif
+#endif
 
   atk_misc_instance = g_object_new (GTK_TYPE_MISC_IMPL, NULL);
 }
