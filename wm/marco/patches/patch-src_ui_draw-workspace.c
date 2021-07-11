$NetBSD: patch-src_ui_draw-workspace.c,v 1.1 2021/07/11 03:32:48 gutteridge Exp $

Fix memory leaks that can lead to significant responsiveness issues.
https://github.com/mate-desktop/marco/commit/76da06f
https://github.com/mate-desktop/marco/issues/685

--- src/ui/draw-workspace.c.orig	2021-03-23 15:55:18.000000000 +0000
+++ src/ui/draw-workspace.c
@@ -131,6 +131,7 @@ draw_window (GtkWidget                  
       /* If the icon is too big, fall back to mini icon. */
       if (icon_w > (winrect->width - 2) || icon_h > (winrect->height - 2))
         {
+          cairo_surface_destroy (icon);
           icon = gdk_cairo_surface_create_from_pixbuf (win->mini_icon, scale, NULL);
           if (icon)
             {
@@ -139,7 +140,10 @@ draw_window (GtkWidget                  
 
               /* Give up. */
               if (icon_w > (winrect->width - 2) || icon_h > (winrect->height - 2))
-                icon = NULL;
+                {
+                  cairo_surface_destroy (icon);
+                  icon = NULL;
+                }
             }
         }
     }
@@ -155,6 +159,8 @@ draw_window (GtkWidget                  
       cairo_clip (cr);
       cairo_paint (cr);
       cairo_restore (cr);
+
+      cairo_surface_destroy (icon);
     }
 
   gtk_style_context_get_color (style, state, &color);
