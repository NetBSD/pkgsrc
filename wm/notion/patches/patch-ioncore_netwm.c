$NetBSD: patch-ioncore_netwm.c,v 1.1 2012/04/18 23:15:19 wiz Exp $

Fixes some fullscreen apps.
From Philipp Hartwig <ph@phhart.de>
on notion-general@lists.sourceforge.net

--- ioncore/netwm.c.orig	2011-10-29 18:19:21.000000000 +0000
+++ ioncore/netwm.c
@@ -95,7 +95,7 @@ void netwm_init_rootwin(WRootWin *rw)
 /*{{{ _NET_WM_STATE */
 
 
-WScreen *netwm_check_initial_fullscreen(WClientWin *cwin)
+bool netwm_check_initial_fullscreen(WClientWin *cwin)
 {
 
     int i, n;
@@ -106,16 +106,16 @@ WScreen *netwm_check_initial_fullscreen(
                    1, TRUE, (uchar**)&data);
     
     if(n<0)
-        return NULL;
+        return FALSE;
     
     for(i=0; i<n; i++){
         if(data[i]==(long)atom_net_wm_state_fullscreen)
-            return region_screen_of((WRegion*)cwin);
+            return TRUE;
     }
     
     XFree((void*)data);
 
-    return NULL;
+    return FALSE;
 }
 
 
