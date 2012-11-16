$NetBSD: patch-lib_libxview_pw_xv__text.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/pw/xv_text.c.orig	2012-11-14 14:57:50.000000000 +0000
+++ lib/libxview/pw/xv_text.c
@@ -37,7 +37,7 @@ pw_char(pw, xw, yw, op, pixfont, c)
     (void) xv_text(pw, xw, yw, op, (Xv_opaque)pixfont, str);
 }
 
-Xv_public int
+Xv_public void
 xv_ttext(window, xbasew, ybasew, op, pixfont, str)
     Xv_opaque       window;
     int             op;
@@ -76,7 +76,7 @@ xv_ttext(window, xbasew, ybasew, op, pix
     XDrawString(display, d, gc, xbasew, ybasew, str, len);
 }
 
-Xv_public int
+Xv_public void
 xv_text(window, xbasew, ybasew, op, pixfont, str)
     Xv_opaque       window;
     int             op;
