$NetBSD: patch-src_vtedraw.cc,v 1.1 2018/06/15 10:44:15 jperkin Exp $

Avoid ambiguous function call.

--- src/vtedraw.cc.orig	2018-05-21 19:31:53.000000000 +0000
+++ src/vtedraw.cc
@@ -1674,13 +1674,13 @@ _vte_draw_draw_line(struct _vte_draw *dr
 static inline double
 _vte_draw_get_undercurl_rad(gint width)
 {
-        return width / 2. / sqrt(2);
+        return width / 2. / sqrt((double)2);
 }
 
 static inline double
 _vte_draw_get_undercurl_arc_height(gint width)
 {
-        return _vte_draw_get_undercurl_rad(width) * (1. - sqrt(2) / 2.);
+        return _vte_draw_get_undercurl_rad(width) * (1. - sqrt((double)2) / 2.);
 }
 
 double
