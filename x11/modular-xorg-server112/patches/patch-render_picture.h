$NetBSD: patch-render_picture.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

Fix CVE-2013-6424 using
http://lists.x.org/archives/xorg-devel/2013-October/037996.html

--- render/picture.h.orig	2012-05-17 17:09:05.000000000 +0000
+++ render/picture.h
@@ -211,7 +211,7 @@ typedef pixman_fixed_t xFixed;
 /* whether 't' is a well defined not obviously empty trapezoid */
 #define xTrapezoidValid(t)  ((t)->left.p1.y != (t)->left.p2.y && \
 			     (t)->right.p1.y != (t)->right.p2.y && \
-			     (int) ((t)->bottom - (t)->top) > 0)
+			     ((t)->bottom > (t)->top))
 
 /*
  * Standard NTSC luminance conversions:
