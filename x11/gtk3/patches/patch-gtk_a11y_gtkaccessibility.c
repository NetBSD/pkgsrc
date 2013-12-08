$NetBSD: patch-gtk_a11y_gtkaccessibility.c,v 1.2 2013/12/08 14:21:37 prlw1 Exp $
 
gtk3-atk-bridge option to avoid dbus dependency.

--- gtk/a11y/gtkaccessibility.c.orig	2013-10-14 16:39:20.000000000 +0000
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
@@ -983,8 +985,10 @@ _gtk_accessibility_init (void)
   do_window_event_initialization ();
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_init (NULL, NULL);
 #endif
+#endif
 
   atk_misc_instance = g_object_new (GTK_TYPE_MISC_IMPL, NULL);
 }
