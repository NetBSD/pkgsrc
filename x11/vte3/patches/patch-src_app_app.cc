$NetBSD: patch-src_app_app.cc,v 1.4 2019/03/07 21:36:07 jmcneill Exp $

Fix NetBSD build.

--- src/app/app.cc.orig	2018-12-10 21:32:12.000000000 +0000
+++ src/app/app.cc
@@ -23,6 +23,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <errno.h>
 
 #include <glib.h>
 #include <glib/gprintf.h>
@@ -308,7 +309,7 @@ public:
                 else
                         alpha = get_alpha();
 
-                GdkRGBA color{bg_color};
+                GdkRGBA color = bg_color;
                 color.alpha = alpha;
                 return color;
         }
@@ -1292,7 +1293,7 @@ vteapp_window_fork(VteappWindow* window,
         auto pid = fork();
         switch (pid) {
         case -1: /* error */
-                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %m");
+                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %s", strerror(errno));
                 return false;
 
         case 0: /* child */ {
