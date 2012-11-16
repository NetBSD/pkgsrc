$NetBSD: patch-lib_libxview_window_window__cms.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/window/window_cms.c.orig	2012-11-14 16:20:06.000000000 +0000
+++ lib/libxview/window/window_cms.c
@@ -24,7 +24,7 @@ Attr_attribute  xv_cms_name_key = NULL;
 void            window_set_cms();
 void		window_set_cmap_property();
 
-Xv_private
+Xv_private void
 window_set_cms_name(win_public, new_name)
     Xv_Window       win_public;
     char           *new_name;
@@ -65,7 +65,7 @@ window_set_cms_name(win_public, new_name
     }
 }
 
-Xv_private
+Xv_private void
 window_set_cms_data(win_public, cms_data)
     Xv_Window       win_public;
     Xv_cmsdata     *cms_data;
