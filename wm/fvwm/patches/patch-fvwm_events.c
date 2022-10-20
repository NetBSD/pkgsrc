$NetBSD: patch-fvwm_events.c,v 1.1 2022/10/20 00:39:50 gutteridge Exp $

Backport "Fix for lock recusion in handle_all_expose()"
https://github.com/fvwmorg/fvwm3/pull/683

--- fvwm/events.c.orig	2018-05-26 11:35:26.000000000 +0000
+++ fvwm/events.c
@@ -258,6 +258,12 @@ static int _pred_weed_accumulate_expose(
 	return 1;
 }
 
+static int _pred_weed_is_expose(
+	Display *display, XEvent *event, XPointer arg)
+{
+	return (event->type == Expose);
+}
+
 static int _pred_weed_handle_expose(
 	Display *display, XEvent *event, XPointer arg)
 {
@@ -4542,7 +4548,8 @@ void handle_all_expose(void)
 
 	saved_event = fev_save_event();
 	FPending(dpy);
-	FWeedIfEvents(dpy, _pred_weed_handle_expose, NULL);
+	FWeedAndHandleIfEvents(dpy, _pred_weed_is_expose,
+			       _pred_weed_handle_expose, NULL);
 	fev_restore_event(saved_event);
 
 	return;
