$NetBSD: patch-applet-activation_main.c,v 1.1.1.1 2012/02/19 14:43:11 imil Exp $

--- applet-activation/main.c.orig	2010-03-25 10:44:53.000000000 +0000
+++ applet-activation/main.c
@@ -222,7 +222,7 @@ main(gint argc, gchar **argv)
 
   if (strcmp(type, "Python") == 0)
   {
-    launch_applet_with ("python", path, exec, uid, window, panel_id);
+    launch_applet_with ("@PYTHONBIN@", path, exec, uid, window, panel_id);
     return 0;
   }
 
