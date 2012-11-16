$NetBSD: patch-lib_libxview_win_win__global.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/win/win_global.c.orig	2012-11-14 16:04:45.000000000 +0000
+++ lib/libxview/win/win_global.c
@@ -46,7 +46,7 @@ int             win_grabiodebug;
 /*
  * Server operations applying globally.
  */
-win_lockdata(window)
+void win_lockdata(window)
     Xv_object       window;
 {
     Xv_Drawable_info *info;
@@ -58,7 +58,7 @@ win_lockdata(window)
     XGrabServer(xv_display(info));
 }
 
-win_unlockdata(window)
+void win_unlockdata(window)
     Xv_object       window;
 {
     Xv_Drawable_info *info;
@@ -99,7 +99,7 @@ xv_win_grab(window, im, cursor_window, c
     if (status)
         *status = 1; /* initialize to be OK */
     if (win_grabiodebug)
-	return;
+	return 0;
     DRAWABLE_INFO_MACRO(window, info);
     display = xv_display(info);
 
@@ -160,7 +160,7 @@ xv_win_grab(window, im, cursor_window, c
     return (GrabSuccess);
 }
 
-Xv_private int
+Xv_private void
 xv_win_ungrab(window, ungrab_pointer, ungrab_kbd, ungrab_server)
     Xv_object       window;
     int		    ungrab_pointer, ungrab_kbd, ungrab_server;
@@ -196,7 +196,7 @@ win_grabio(window)
     return (win_xgrabio_async(window, im, 0, 0));
 }
 
-win_xgrabio_sync(window, im, cursor_window, cursor)
+int win_xgrabio_sync(window, im, cursor_window, cursor)
     Xv_object       window;
     Inputmask      *im;
     Xv_object       cursor_window;
@@ -207,7 +207,7 @@ win_xgrabio_sync(window, im, cursor_wind
     unsigned int    xevent_mask = win_im_to_xmask(window, im);
 
     if (win_grabiodebug)
-	return;
+	return 0;
     DRAWABLE_INFO_MACRO(window, info);
     display = xv_display(info);
 
@@ -245,7 +245,7 @@ win_xgrabio_sync(window, im, cursor_wind
     return (1);
 }
 
-win_xgrabio_async(window, im, cursor_window, cursor)
+int win_xgrabio_async(window, im, cursor_window, cursor)
     Xv_object       window;
     Inputmask      *im;
     Xv_object       cursor_window;
@@ -256,7 +256,7 @@ win_xgrabio_async(window, im, cursor_win
     unsigned int    xevent_mask = win_im_to_xmask(window, im);
 
     if (win_grabiodebug)
-	return;
+	return 0;
     DRAWABLE_INFO_MACRO(window, info);
     display = xv_display(info);
 
@@ -309,7 +309,7 @@ win_set_grabio_params(window, im, cursor
 			     CurrentTime);
 }
 
-win_releaseio(window)
+void win_releaseio(window)
     Xv_object       window;
 {
     Xv_Drawable_info *info;
