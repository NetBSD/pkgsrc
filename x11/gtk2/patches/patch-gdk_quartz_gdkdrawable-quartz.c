$NetBSD: patch-gdk_quartz_gdkdrawable-quartz.c,v 1.1 2025/08/26 04:36:17 pho Exp $

Fix "Source with depth 1 unsupported" warnings on Darwin/Quartz.
- Upstream ticket: https://gitlab.gnome.org/GNOME/gtk/-/issues/580
- Patch from: https://trac.macports.org/ticket/69291

--- gdk/quartz/gdkdrawable-quartz.c.orig	2020-12-18 05:50:58.000000000 +0000
+++ gdk/quartz/gdkdrawable-quartz.c
@@ -462,12 +462,7 @@ gdk_quartz_draw_drawable (GdkDrawable *d
     }
 
   /* Handle drawable and pixmap sources. */
-  if (src_depth == 1)
-    {
-      /* FIXME: src depth 1 is not supported yet */
-      g_warning ("Source with depth 1 unsupported");
-    }
-  else if (dest_depth != 0 && src_depth == dest_depth)
+  if (dest_depth != 0 && src_depth == dest_depth)
     {
       GdkPixmapImplQuartz *pixmap_impl = GDK_PIXMAP_IMPL_QUARTZ (src_impl);
       CGContextRef context = gdk_quartz_drawable_get_context (drawable, FALSE);
