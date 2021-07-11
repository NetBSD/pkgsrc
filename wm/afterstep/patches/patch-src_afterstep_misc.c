$NetBSD: patch-src_afterstep_misc.c,v 1.3 2021/07/11 12:13:17 bsiegert Exp $

Patch up gcc inline mess.

--- src/afterstep/misc.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/misc.c
@@ -32,13 +32,13 @@
 /****************************************************************************/
 /* window management specifics - button ungrabbing convinience functions:   */
 /****************************************************************************/
-inline void ungrab_window_buttons (Window w)
+void ungrab_window_buttons (Window w)
 {
 	LOCAL_DEBUG_OUT ("w = %lX", w);
 	XUngrabButton (dpy, AnyButton, AnyModifier, w);
 }
 
-inline void ungrab_window_keys (Window w)
+void ungrab_window_keys (Window w)
 {
 	XUngrabKey (dpy, AnyKey, AnyModifier, w);
 }
