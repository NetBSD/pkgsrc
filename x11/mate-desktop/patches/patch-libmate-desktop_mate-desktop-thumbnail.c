$NetBSD: patch-libmate-desktop_mate-desktop-thumbnail.c,v 1.1 2016/05/21 18:52:35 youri Exp $

* for the case time_t != long

--- libmate-desktop/mate-desktop-thumbnail.c.orig	2014-02-09 16:53:41.000000000 +0000
+++ libmate-desktop/mate-desktop-thumbnail.c
@@ -36,6 +36,9 @@
 #include <string.h>
 #include <glib.h>
 #include <stdio.h>
+#ifdef HAVE_STDINT_H
+#include <stdint.h>
+#endif
 
 #define GDK_PIXBUF_ENABLE_BACKEND
 #include <gdk-pixbuf/gdk-pixbuf.h>
@@ -1513,7 +1516,7 @@ mate_desktop_thumbnail_factory_save_thum
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  original_mtime);
+  g_snprintf (mtime_str, 21, "%jd",  (intmax_t)original_mtime);
   width = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Width");
   height = gdk_pixbuf_get_option (thumbnail, "tEXt::Thumb::Image::Height");
 
@@ -1624,7 +1627,7 @@ mate_desktop_thumbnail_factory_create_fa
     }
   close (tmp_fd);
   
-  g_snprintf (mtime_str, 21, "%ld",  mtime);
+  g_snprintf (mtime_str, 21, "%jd",  (intmax_t)mtime);
   pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB, TRUE, 8, 1, 1);
   saved_ok  = gdk_pixbuf_save (pixbuf,
 			       tmp_path,
