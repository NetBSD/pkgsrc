$NetBSD: patch-src_app_app.cc,v 1.2 2018/06/15 10:44:15 jperkin Exp $

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
@@ -78,8 +79,8 @@ public:
         char** exec_argv{nullptr};
         char** environment{nullptr};
         GdkPixbuf* background_pixbuf{nullptr};
-        GdkRGBA bg_color{1.0, 1.0, 1.0, 1.0};
-        GdkRGBA fg_color{0.0, 0.0, 0.0, 1.0};
+        GdkRGBA bg_color{(gdouble)1.0, (gdouble)1.0, (gdouble)1.0, (gdouble)1.0};
+        GdkRGBA fg_color{(gdouble)0.0, (gdouble)0.0, (gdouble)0.0, (gdouble)1.0};
         GdkRGBA cursor_bg_color{};
         GdkRGBA cursor_fg_color{};
         GdkRGBA hl_bg_color{};
@@ -1257,7 +1258,7 @@ vteapp_window_fork(VteappWindow* window,
         auto pid = fork();
         switch (pid) {
         case -1: /* error */
-                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %m");
+                g_set_error(error, G_IO_ERROR, G_IO_ERROR_FAILED, "Error forking: %s", strerror(errno));
                 return false;
 
         case 0: /* child */ {
