$NetBSD: patch-src_afterstep_asinternals.h,v 1.3 2021/07/11 12:13:17 bsiegert Exp $

Patch up gcc inline mess.

--- src/afterstep/asinternals.h.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/asinternals.h
@@ -689,8 +689,8 @@ void ParsePopupEntry (char *tline, FILE 
 
 
 /*************************** misc.c *********************************/
-inline void ungrab_window_buttons( Window w );
-inline void ungrab_window_keys (Window w );
+void ungrab_window_buttons( Window w );
+void ungrab_window_keys (Window w );
 void MyXGrabButton ( unsigned button, unsigned modifiers,
 				Window grab_window, Bool owner_events, unsigned event_mask,
 				int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor);
