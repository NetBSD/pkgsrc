$NetBSD: patch-lib_libxview_rect_rect.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/rect/rect.h.orig	1993-06-29 05:15:17.000000000 +0000
+++ lib/libxview/rect/rect.h
@@ -135,10 +135,7 @@ EXTERN_FUNCTION (unsigned rect_clipvecto
 EXTERN_FUNCTION (unsigned rect_order, (Rect *rl, Rect *r2, int sortorder));
 EXTERN_FUNCTION (int rect_right_of, (Rect *rect1, Rect *rect2));
 EXTERN_FUNCTION (int rect_below, (Rect *rect1, Rect *rect2));
-#ifdef _OTHER_RECT_FUNCTIONS
-
 EXTERN_FUNCTION (void rect_intersection, (Rect *rl, Rect *r2, Rect *r));
 EXTERN_FUNCTION (int rect_distance, (Rect *rect, int x, int y, int * x_used, int * y_used));
-#endif /* _OTHER_RECT_FUNCTIONS */
 
 #endif /* ~xview_rect_DEFINED */
