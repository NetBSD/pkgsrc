$NetBSD: patch-libs_FEvent.c,v 1.1 2022/10/20 00:39:50 gutteridge Exp $

Backport "Fix for lock recusion in handle_all_expose()"
https://github.com/fvwmorg/fvwm3/pull/683

--- libs/FEvent.c.orig	2018-05-26 11:35:26.000000000 +0000
+++ libs/FEvent.c
@@ -532,6 +532,28 @@ int FWeedIfEvents(
 	return weed_args.count;
 }
 
+int FWeedAndHandleIfEvents(
+	Display *display,
+	int (*weed_predicate) (Display *display, XEvent *event, XPointer arg),
+	int (*handler) (Display *display, XEvent *event, XPointer arg),
+	XPointer arg)
+{
+	_fev_weed_args weed_args;
+	XEvent e;
+
+	assert(fev_is_invalid_event_type_set);
+	memset(&weed_args, 0, sizeof(weed_args));
+	weed_args.weed_predicate = weed_predicate;
+	weed_args.arg = arg;
+	if (FCheckPeekIfEvent(display, &e, _fev_pred_weed_if,
+			      (XPointer)&weed_args)) {
+		handler(display, &e, arg);
+	}
+	_fev_pred_weed_if_finish(&weed_args);
+
+	return weed_args.count;
+}
+
 int FWeedIfWindowEvents(
 	Display *display, Window window,
 	int (*weed_predicate) (
