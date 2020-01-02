$NetBSD: patch-src_misc.c,v 1.1 2020/01/02 17:00:14 gutteridge Exp $

Disable broken TRACE() call.
https://bugzilla.xfce.org/show_bug.cgi?id=16329

--- src/misc.c.orig	2019-08-11 20:53:12.000000000 +0000
+++ src/misc.c
@@ -51,7 +51,7 @@ getMouseXY (ScreenInfo *screen_info, gin
     guint mask;
     gint x1, y1;
 
-    TRACE ("window (0x%lx)", w);
+    /* TRACE ("window (0x%lx)", w); */
 
     myDisplayErrorTrapPush (screen_info->display_info);
     XQueryPointer (myScreenGetXDisplay (screen_info), screen_info->xroot, &w1, &w2, &x1, &y1, x2, y2, &mask);
