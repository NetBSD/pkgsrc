$NetBSD: patch-libxfcegui4_xfce-exec.c,v 1.1 2015/04/21 08:56:43 jperkin Exp $

Fixes compiling with libxfce4util 4.11+
--- libxfcegui4/xfce-exec.c.orig	2012-04-28 20:10:43.000000000 +0000
+++ libxfcegui4/xfce-exec.c
@@ -59,6 +59,7 @@
 
 #ifdef HAVE__NSGETENVIRON
 /* for support under apple/darwin */
+#include <crt_externs.h>
 #define environ (*_NSGetEnviron())
 #elif !HAVE_DECL_ENVIRON
 /* try extern if environ is not defined in unistd.h */
@@ -79,7 +80,7 @@ child_setup_sync(gpointer user_data)
 #ifndef G_OS_WIN32
     gchar *dpyname = user_data;
     
-    xfce_setenv ("DISPLAY", dpyname, TRUE);
+    g_setenv ("DISPLAY", dpyname, TRUE);
 #endif
 }
 
