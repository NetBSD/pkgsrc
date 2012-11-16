$NetBSD: patch-lib_libxview_panel_p__num__txt.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/panel/p_num_txt.c.orig	1993-06-29 05:17:03.000000000 +0000
+++ lib/libxview/panel/p_num_txt.c
@@ -698,7 +698,7 @@ num_textitem_scroll_itimer_func( item, w
     Event		event;
  
     if (dp->btn_state & OLGX_INACTIVE)
-        return;
+        return (NOTIFY_DONE);
  
     if (dp->btn_state & UP_SELECTED)
     {
@@ -729,6 +729,7 @@ num_textitem_scroll_itimer_func( item, w
         if (dp->btn_state & DOWN_INACTIVE)
             panel_autoscroll_stop_itimer( item );
     }
+    return (NOTIFY_DONE);
 } /* num_textitem_scroll_itimer_func */
 
 
