$NetBSD: patch-xicc.c,v 1.1 2012/03/18 21:20:49 jakllsch Exp $

--- xicc.c.orig	2005-06-16 08:31:47.000000000 +0000
+++ xicc.c
@@ -9,6 +9,11 @@ int main(int argc, char **argv) {
   char *profile;
   gsize length;
 
+  if (argc != 2) {
+    g_printerr("Missing ICC file argument\n");
+    return 1;
+  }
+
   dpy = XOpenDisplay(NULL);
   if (dpy == NULL) {
     g_printerr("Cannot open display\n");
@@ -27,7 +32,7 @@ int main(int argc, char **argv) {
     return 1;
   }
 
-  XChangeProperty (dpy, DefaultRootWindow (dpy), icc_atom, XA_CARDINAL, 32, PropModeReplace, profile, length/sizeof(long));
+  XChangeProperty (dpy, DefaultRootWindow (dpy), icc_atom, XA_CARDINAL, 8, PropModeReplace, profile, length);
 
   XCloseDisplay (dpy);
   return 0;
