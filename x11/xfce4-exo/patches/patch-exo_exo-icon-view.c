$NetBSD: patch-exo_exo-icon-view.c,v 1.1 2019/12/16 00:44:34 gutteridge Exp $

Revert padding patches that add too much padding in the Thunar compact view.
https://bugzilla.xfce.org/show_bug.cgi?id=16196
https://git.xfce.org/xfce/exo/commit?id=a925f0b2af7249fd5119cdc27cb6a306b42e795e

--- exo/exo-icon-view.c.orig	2019-11-20 01:19:46.000000000 +0000
+++ exo/exo-icon-view.c
@@ -3915,25 +3915,8 @@ exo_icon_view_calculate_item_size (ExoIc
         gtk_cell_renderer_get_preferred_size (info->cell, GTK_WIDGET (icon_view),
                                               &req, NULL);
 
-        if (info->is_text)
-          {
-            GdkRectangle cell_area, aligned_area;
-            gint cell_xpad, cell_ypad;
-
-            cell_area.width = req.width;
-            cell_area.height = req.height;
-            gtk_cell_renderer_get_aligned_area (info->cell, GTK_WIDGET (icon_view),
-                                                0, &cell_area, &aligned_area);
-            gtk_cell_renderer_get_padding (info->cell, &cell_xpad, &cell_ypad);
-
-            item->box[info->position].width = aligned_area.width + 2*cell_xpad;
-            item->box[info->position].height = aligned_area.height + 2*cell_ypad;
-          }
-        else
-          {
-            item->box[info->position].width = req.width;
-            item->box[info->position].height = req.height;
-          }
+        item->box[info->position].width = req.width;
+        item->box[info->position].height = req.height;
       }
 #else
       gtk_cell_renderer_get_size (info->cell, GTK_WIDGET (icon_view),
