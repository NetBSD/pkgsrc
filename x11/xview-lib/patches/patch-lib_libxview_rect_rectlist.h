$NetBSD: patch-lib_libxview_rect_rectlist.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/rect/rectlist.h.orig	2012-11-14 15:15:09.000000000 +0000
+++ lib/libxview/rect/rectlist.h
@@ -100,8 +100,6 @@ EXTERN_FUNCTION (unsigned rl_rectinterse
 EXTERN_FUNCTION (unsigned rl_equalrect, (Rect *r, Rectlist *rl));
 EXTERN_FUNCTION (unsigned rl_includespoint, (Rectlist *r, int x, int y));
 
-#ifdef xview_other_rl_funcs
-
 EXTERN_FUNCTION (void rl_rectintersection, (Rect *r, Rectlist *rl1, Rectlist *rl));
 EXTERN_FUNCTION (void rl_rectunion, (Rect *r, Rectlist *rl1, Rectlist *rl));
 EXTERN_FUNCTION (void rl_rectdifference, (Rect *r, Rectlist *rl1, Rectlist *rl));
@@ -116,6 +114,4 @@ EXTERN_FUNCTION (void rl_coalesce, (Rect
 EXTERN_FUNCTION (void rl_normalize, (Rectlist *rl));
 EXTERN_FUNCTION (void rl_print, (Rectlist *rl, char *tag));
 
-#endif /* xview_other_rl_funcs */
-
 #endif	/* ~xview_rectlist_DEFINED */
