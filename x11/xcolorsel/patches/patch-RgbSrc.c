$NetBSD: patch-RgbSrc.c,v 1.1 2015/10/14 20:17:28 wiz Exp $

--- RgbSrc.c.orig	1994-11-13 22:14:31.000000000 +0000
+++ RgbSrc.c
@@ -134,7 +134,7 @@ RgbSrcClassRec rgbSrcClassRec = {
   { /* text_src fields */
     /* Read			*/	XtInheritRead,
     /* Replace			*/	XtInheritReplace,
-    /* Scan			*/	(_XawTextPositionFunc)myscan,
+    /* Scan			*/	myscan,
     /* Search			*/	XtInheritSearch,
     /* SetSelection		*/	XtInheritSetSelection,
     /* ConvertSelection		*/	XtInheritConvertSelection,
