$NetBSD: patch-gtk_a11y_gail.c,v 1.1 2013/05/11 19:49:15 riastradh Exp $

--- gtk/a11y/gail.c.orig	2013-01-07 10:50:02.000000000 +0000
+++ gtk/a11y/gail.c
@@ -36,8 +36,10 @@
 #include "gailmisc.h"
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
 #include <atk-bridge.h>
 #endif
+#endif
 
 static gboolean gail_focus_watcher      (GSignalInvocationHint *ihint,
                                          guint                  n_param_values,
@@ -808,8 +810,10 @@ _gtk_accessibility_shutdown (void)
   g_clear_object (&atk_misc_instance);
 
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_cleanup ();
 #endif
+#endif
   _gail_util_uninstall ();
 }
 
@@ -828,8 +832,10 @@ _gtk_accessibility_init (void)
 
   _gail_util_install ();
 #ifdef GDK_WINDOWING_X11
+#ifdef HAVE_ATK_BRIDGE
   atk_bridge_adaptor_init (NULL, NULL);
 #endif
+#endif
 
   atk_misc_instance = g_object_new (GAIL_TYPE_MISC, NULL);
 }
