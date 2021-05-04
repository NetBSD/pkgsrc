$NetBSD: patch-mlvwm_menus.c,v 1.1 2021/05/04 14:09:52 nia Exp $

Replace C++ style comments with C style comments for compatibility
with C89.

--- mlvwm/menus.c.orig	2021-03-23 20:39:27.000000000 +0000
+++ mlvwm/menus.c
@@ -508,7 +508,7 @@ Bool ChoiseMenu( MenuLabel *m, Window *e
 		XMaskEvent( dpy, ExposureMask | ButtonReleaseMask | ButtonPressMask|
 						EnterWindowMask | PointerMotionMask | ButtonMotionMask,
 						&Event );
-//		XNextEvent( dpy, &Event );
+/*		XNextEvent( dpy, &Event ); */
 		switch( Event.type ){
 		case Expose:
 			if( XFindContext( dpy, Event.xany.window, MenuContext,
@@ -631,7 +631,7 @@ void press_menu( MenuLabel *m )
 		XMaskEvent( dpy, ExposureMask | ButtonReleaseMask | ButtonPressMask|
 						EnterWindowMask | PointerMotionMask | ButtonMotionMask,
 						&Event );
-//		XNextEvent( dpy, &Event );
+/*		XNextEvent( dpy, &Event ); */
 		switch( Event.type ){
 		case Expose:
 			if( mapped && Event.xany.window==mapped->PullWin &&
@@ -792,7 +792,7 @@ void CreateMenuLabel( MenuLabel *ml )
 	if( ml->flags&SWALLOW ){
 		if( SwallowMenu( ml ) ){
 			XSetWindowBorderWidth( dpy, ml->LabelWin, 0 );
-//			XResizeWindow( dpy, ml->LabelWin, ml->LabelWidth, MENUB_H-2 );
+/*			XResizeWindow( dpy, ml->LabelWin, ml->LabelWidth, MENUB_H-2 ); */
 			XReparentWindow( dpy, ml->LabelWin, Scr.MenuBar, 0, 0 );
 			ml->LabelWidth += 6;
 		}
