$NetBSD: patch-RgbSink.c,v 1.1 2015/10/14 20:17:28 wiz Exp $

--- RgbSink.c.orig	1994-12-13 21:32:37.000000000 +0000
+++ RgbSink.c
@@ -147,7 +147,7 @@ RgbSinkClassRec rgbSinkClassRec = {
     /* extension		*/	NULL
   },
   { /* text_sink fields */
-    /* DisplayText		*/	(_XawSinkVoidFunc) mydisp,
+    /* DisplayText		*/	mydisp,
     /* InsertCursor		*/	XtInheritInsertCursor,
     /* ClearToBackground	*/	XtInheritClearToBackground,
     /* FindPosition		*/	XtInheritFindPosition,
