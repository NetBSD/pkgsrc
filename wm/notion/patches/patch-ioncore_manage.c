$NetBSD: patch-ioncore_manage.c,v 1.1 2012/04/18 23:15:19 wiz Exp $

Fixes some fullscreen apps.
From Philipp Hartwig <ph@phhart.de>
on notion-general@lists.sourceforge.net

--- ioncore/manage.c.orig	2011-10-29 18:19:21.000000000 +0000
+++ ioncore/manage.c
@@ -151,8 +151,8 @@ static bool try_fullscreen(WClientWin *c
         fs_scr=dflt;
     }
 
-    if(fs_scr==NULL)
-        fs_scr=netwm_check_initial_fullscreen(cwin);
+    if(fs_scr==NULL && netwm_check_initial_fullscreen(cwin))
+        fs_scr=dflt;
 
     if(fs_scr==NULL)
         fs_scr=clientwin_fullscreen_chkrq(cwin, param->geom.w, param->geom.h);
