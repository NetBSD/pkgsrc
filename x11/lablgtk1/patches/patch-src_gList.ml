$NetBSD: patch-src_gList.ml,v 1.1 2014/10/20 11:00:25 jaapb Exp $

Remove duplicate method.
--- src/gList.ml.orig	2014-10-20 10:52:23.000000000 +0000
+++ src/gList.ml	2014-10-20 10:52:40.000000000 +0000
@@ -126,7 +126,6 @@
   method set_vadjustment adj =
     CList.set_vadjustment obj (GData.as_adjustment adj)
   method set_shadow_type = CList.set_shadow_type obj
-  method set_button_actions = CList.set_button_actions obj
   method set_selection_mode = CList.set_selection_mode obj
   method set_reorderable = CList.set_reorderable obj
   method set_use_drag_icons = CList.set_use_drag_icons obj
