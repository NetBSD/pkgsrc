$NetBSD: patch-src_afterstep_asinternals.h,v 1.1 2012/05/04 16:36:11 joerg Exp $

--- src/afterstep/asinternals.h.orig	2012-05-04 14:35:02.000000000 +0000
+++ src/afterstep/asinternals.h
@@ -607,8 +607,8 @@ void ParsePopupEntry (char *tline, FILE 
 
 
 /*************************** misc.c *********************************/
-inline void ungrab_window_buttons( Window w );
-inline void ungrab_window_keys (Window w );
+void ungrab_window_buttons( Window w );
+void ungrab_window_keys (Window w );
 void MyXGrabButton ( unsigned button, unsigned modifiers,
                 Window grab_window, Bool owner_events, unsigned event_mask,
                 int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor);
