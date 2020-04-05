$NetBSD: patch-tools_mate-session-check-accelerated.c,v 1.1 2020/04/05 16:05:44 bsiegert Exp $

Make GLESv2 optional.
https://github.com/mate-desktop/mate-session-manager/pull/237

--- tools/mate-session-check-accelerated.c.orig	2020-02-10 12:43:35.000000000 +0000
+++ tools/mate-session-check-accelerated.c
@@ -21,6 +21,8 @@
  *   Colin Walters <walters@verbum.org>
  */
 
+#include <config.h>
+
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -131,13 +133,17 @@ main (int argc, char **argv)
         GdkDisplay *display = NULL;
         int estatus;
         char *gl_helper_argv[] = { LIBEXECDIR "/mate-session-check-accelerated-gl-helper", "--print-renderer", NULL };
+#ifdef HAVE_GLESV2
         char *gles_helper_argv[] = { LIBEXECDIR "/mate-session-check-accelerated-gles-helper", "--print-renderer", NULL };
+        GError *gles_error = NULL;
+        char *gles_renderer_string = NULL;
+#endif
         char *renderer_string = NULL;
-        char *gl_renderer_string = NULL, *gles_renderer_string = NULL;
+        char *gl_renderer_string = NULL;
         gboolean gl_software_rendering = FALSE, gles_software_rendering = FALSE;
         Window rootwin;
         glong is_accelerated, is_software_rendering;
-        GError *gl_error = NULL, *gles_error = NULL;
+        GError *gl_error = NULL;
 
         gtk_init (NULL, NULL);
 
@@ -241,6 +247,7 @@ main (int argc, char **argv)
                 g_printerr ("mate-session-check-accelerated: GL Helper exited with code %d\n", estatus);
         }
 
+#ifdef HAVE_GLESV2
         /* Then, try the GLES helper */
         if (g_spawn_sync (NULL, (char **) gles_helper_argv, NULL, 0,
                            NULL, NULL, &gles_renderer_string, NULL, &estatus, &gles_error)) {
@@ -253,6 +260,7 @@ main (int argc, char **argv)
 
                 g_printerr ("mate-session-check-accelerated: GLES Helper exited with code %d\n", estatus);
         }
+#endif
 
         /* If we got here, GL software rendering is our best bet */
         if (gl_software_rendering || gles_software_rendering) {
@@ -261,8 +269,10 @@ main (int argc, char **argv)
 
                 if (gl_software_rendering)
                         renderer_string = gl_renderer_string;
+#ifdef HAVE_GLESV2
                 else if (gles_software_rendering)
                         renderer_string = gles_renderer_string;
+#endif
 
                 goto finish;
         }
@@ -273,10 +283,12 @@ main (int argc, char **argv)
                 g_clear_error (&gl_error);
         }
 
+#ifdef HAVE_GLESV2
         if (gles_error != NULL) {
                 g_printerr ("mate-session-check-accelerated: Failed to run GLES helper: %s\n", gles_error->message);
                 g_clear_error (&gles_error);
         }
+#endif
 
  finish:
 	if (is_accelerated) {
@@ -306,7 +318,9 @@ main (int argc, char **argv)
         gdk_display_sync (display);
 
         g_free (gl_renderer_string);
+#ifdef HAVE_GLESV2
         g_free (gles_renderer_string);
+#endif
 
         return is_accelerated ? 0 : 1;
 }
