$NetBSD: patch-mozilla_widget_gtk_nsWindow.cpp,v 1.1 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/widget/gtk/nsWindow.cpp.orig	2014-12-03 06:23:27.000000000 +0000
+++ mozilla/widget/gtk/nsWindow.cpp
@@ -1294,13 +1294,7 @@ SetUserTimeAndStartupIDForActivatedWindo
     }
 
     if (sn_launchee_context_get_id_has_timestamp(ctx)) {
-        PRLibrary* gtkLibrary;
-        SetUserTimeFunc setUserTimeFunc = (SetUserTimeFunc)
-            PR_FindFunctionSymbolAndLibrary("gdk_x11_window_set_user_time", &gtkLibrary);
-        if (setUserTimeFunc) {
-            setUserTimeFunc(gdkWindow, sn_launchee_context_get_timestamp(ctx));
-            PR_UnloadLibrary(gtkLibrary);
-        }
+        gdk_x11_window_set_user_time(gdkWindow, sn_launchee_context_get_timestamp(ctx));
     }
 
     sn_launchee_context_setup_window(ctx, gdk_x11_window_get_xid(gdkWindow));
