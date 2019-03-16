$NetBSD: patch-ioncore_group.c,v 1.2 2019/03/16 11:06:39 wiz Exp $

Xutf8TextListToTextProperty needs a NULL terminated list of pointers.
https://github.com/raboof/notion/pull/70

--- ioncore/group.c.orig	2017-05-05 14:55:07.000000000 +0000
+++ ioncore/group.c
@@ -349,7 +349,7 @@ void group_managed_notify(WGroup *ws, WR
 
 bool group_init(WGroup *ws, WWindow *par, const WFitParams *fp, const char *name)
 {
-    const char *p[1];
+    const char *p[2];
 
     ws->current_managed=NULL;
     ws->managed_stdisp=NULL;
@@ -365,6 +365,7 @@ bool group_init(WGroup *ws, WWindow *par
         return FALSE;
 
     p[0] = name;
+    p[1] = NULL;
     xwindow_set_text_property(ws->dummywin, XA_WM_NAME, p, 1);
 
     region_init(&ws->reg, par, fp);
