$NetBSD: patch-tests_wallclock-reftest.c,v 1.1 2020/11/04 12:12:48 nia Exp $

Disable tests that rely on uselocale()

--- tests/wallclock-reftest.c.orig	2020-10-05 19:11:19.000000000 +0000
+++ tests/wallclock-reftest.c
@@ -26,6 +26,9 @@
 #include <gtk/gtk.h>
 #define GNOME_DESKTOP_USE_UNSTABLE_API 1
 #include <libgnome-desktop/gnome-wall-clock.h>
+#ifdef __APPLE__
+#include <xlocale.h>
+#endif
 
 static const char *output_dir = NULL;
 
@@ -439,21 +442,15 @@ test_ui_file (GFile         *file,
   GnomeWallClock *clock;
   GDateTime *datetime;
   char *str;
-  locale_t loc, previous_locale;
+  g_autofree char *previous_locale;
 
   ui_file = g_file_get_path (file);
 
   locale = get_locale_for_file (ui_file);
   g_assert (locale);
-  loc = newlocale (LC_ALL_MASK, locale, (locale_t) 0);
-  if (loc == (locale_t)0)
-    {
-      g_test_message ("locale '%s' not found", locale);
-      g_test_fail();
-      return;
-    }
-  previous_locale = uselocale (loc);
-  g_assert_true (previous_locale != (locale_t) 0);
+  previous_locale = g_strdup (setlocale (LC_ALL_MASK, NULL));
+  g_assert_true (previous_locale != NULL);
+  setlocale (LC_ALL_MASK, locale);
 
   clock = gnome_wall_clock_new ();
   datetime = g_date_time_new_local (2014, 5, 28, 23, 59, 59);
@@ -465,8 +462,7 @@ test_ui_file (GFile         *file,
   g_date_time_unref (datetime);
   g_object_unref (clock);
 
-  uselocale (previous_locale);
-  freelocale (loc);
+  setlocale (LC_ALL_MASK, previous_locale);
 
   provider = add_extra_css (ui_file, ".css");
 
@@ -616,3 +612,4 @@ main (int argc, char **argv)
 
   return g_test_run ();
 }
+
