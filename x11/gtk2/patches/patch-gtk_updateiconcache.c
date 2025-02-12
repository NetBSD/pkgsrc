$NetBSD: patch-gtk_updateiconcache.c,v 1.1 2025/02/12 05:07:23 rillig Exp $

https://gitlab.gnome.org/GNOME/gtk/-/issues/7332

Add error handling to the option parsing. Without this error handling,
option parsing was skipped on character conversion errors, and in turn,
the file "--force/theme.index" was not found.

Remove custom error handling, as it was missing proper error handling in
the case where the message could not be converted from character set
"UTF-8" to "646" when running with LC_ALL=C instead of
LC_ALL=en_US.UTF-8.

--- gtk/updateiconcache.c.orig	2020-12-18 05:50:58.000000000 +0000
+++ gtk/updateiconcache.c
@@ -1667,43 +1667,16 @@ static GOptionEntry args[] = {
   { NULL }
 };
 
-static void
-printerr_handler (const gchar *string)
-{
-  const gchar *charset;
-
-  fputs (g_get_prgname (), stderr);
-  fputs (": ", stderr);
-  if (g_get_charset (&charset))
-    fputs (string, stderr); /* charset is UTF-8 already */
-  else
-    {
-      gchar *result;
-
-      result = g_convert_with_fallback (string, -1, charset, "UTF-8", "?", NULL, NULL, NULL);
-      
-      if (result)
-        {
-          fputs (result, stderr);
-          g_free (result);
-        }
-   
-      fflush (stderr);
-    }
-}
-
-
 int
 main (int argc, char **argv)
 {
   gchar *path;
   GOptionContext *context;
+  GError *error = NULL;
 
   if (argc < 2)
     return 0;
 
-  g_set_printerr_handler (printerr_handler);
-  
   setlocale (LC_ALL, "");
 
 #ifdef ENABLE_NLS
@@ -1716,8 +1689,12 @@ main (int argc, char **argv)
   context = g_option_context_new ("ICONPATH");
   g_option_context_add_main_entries (context, args, GETTEXT_PACKAGE);
 
-  g_option_context_parse (context, &argc, &argv, NULL);
-  
+  if (!g_option_context_parse (context, &argc, &argv, &error))
+    {
+      g_printerr ("%s\n", error->message);
+      exit (1);
+    }
+
   path = argv[1];
 #ifdef G_OS_WIN32
   path = g_locale_to_utf8 (path, -1, NULL, NULL, NULL);
