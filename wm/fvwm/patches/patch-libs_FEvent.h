$NetBSD: patch-libs_FEvent.h,v 1.1 2022/10/20 00:39:50 gutteridge Exp $

Backport "Fix for lock recusion in handle_all_expose()"
https://github.com/fvwmorg/fvwm3/pull/683

--- libs/FEvent.h.orig	2016-10-15 14:51:45.000000000 +0000
+++ libs/FEvent.h
@@ -113,6 +113,14 @@ int FWeedIfEvents(
 		Display *display, XEvent *current_event, XPointer arg),
 	XPointer arg);
 
+/* Same as FWeedIfEvents but with a second callback out of XLockDisplay()
+ * to handle events in a lock-safe manner */
+int FWeedAndHandleIfEvents(
+	Display *display,
+	int (*weed_predicate) (Display *display, XEvent *event, XPointer arg),
+	int (*handler) (Display *display, XEvent *event, XPointer arg),
+	XPointer arg);
+
 /* Same as FWeedIfEvents but weeds only events for the given window.  The
  * weed_predicate is only called for events with a matching window.  */
 int FWeedIfWindowEvents(
