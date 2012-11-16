$NetBSD: patch-lib_libxview_pw_pixwin.h,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/pw/pixwin.h.orig	2012-11-14 14:58:02.000000000 +0000
+++ lib/libxview/pw/pixwin.h
@@ -143,8 +143,8 @@ EXTERN_FUNCTION (int xv_read, (Pixrect *
 EXTERN_FUNCTION (int xv_replrop, (Xv_opaque window, int op, int xw, int yw, int width, int height, Pixrect *pr, int xr, int yr)); 
 EXTERN_FUNCTION (int xv_rop, (Xv_opaque window, int op, int x, int y, int width, int height, Pixrect *pr, int xr, int yr));
 EXTERN_FUNCTION (int xv_stencil, (Xv_opaque window, int op, int dx, int dy, int width, int height, Pixrect *stpr, int stx, int sty, Pixrect *spr, int sx, int sy));
-EXTERN_FUNCTION (int xv_text, (Xv_opaque window, int op, int xbasew, int ybasew, Xv_opaque font, char *str));
-EXTERN_FUNCTION (int xv_ttext, (Xv_opaque window, int xbasew, int ybasew, int op, Xv_opaque font, char *str));
+EXTERN_FUNCTION (void xv_text, (Xv_opaque window, int op, int xbasew, int ybasew, Xv_opaque font, char *str));
+EXTERN_FUNCTION (void xv_ttext, (Xv_opaque window, int xbasew, int ybasew, int op, Xv_opaque font, char *str));
 EXTERN_FUNCTION (int xv_vector, (Xv_opaque window, int x0, int y0, int x1, int y1, int op, int cms_index));
 EXTERN_FUNCTION (int pw_batchrop, (Pixwin *pw, int x, int y, int op, struct pr_prpos *sbp, int m));
 EXTERN_FUNCTION (int pw_get, (Xv_opaque xv_drawable, int x, int y));
