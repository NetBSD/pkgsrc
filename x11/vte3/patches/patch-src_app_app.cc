$NetBSD: patch-src_app_app.cc,v 1.3 2018/06/21 09:34:50 jperkin Exp $

Fix NetBSD build.

--- src/app/app.cc.orig	2018-05-21 19:31:53.000000000 +0000
+++ src/app/app.cc
@@ -22,6 +22,7 @@
 #include <locale.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <errno.h>
 
 #include <glib.h>
 #include <glib/gprintf.h>
@@ -306,7 +307,7 @@ public:
                 else
                         alpha = get_alpha();
 
-                GdkRGBA color{bg_color};
+                GdkRGBA color = bg_color;
                 color.alpha = alpha;
                 return color;
         }
@@ -1257,7 +1258,7 @@ vteapp_window_fork(VteappWindow* window,
         auto pid = fork();
         switch (pid) {
         case -1: /* error */
-                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %m");
+                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %s", strerror(errno));
                 return false;
 
         case 0: /* child */ {
