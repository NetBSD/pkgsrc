$NetBSD: patch-ioncore_netwm.h,v 1.1 2012/04/18 23:15:19 wiz Exp $

Fixes some fullscreen apps.
From Philipp Hartwig <ph@phhart.de>
on notion-general@lists.sourceforge.net

--- ioncore/netwm.h.orig	2011-10-29 18:19:21.000000000 +0000
+++ ioncore/netwm.h
@@ -20,7 +20,7 @@
 extern void netwm_init();
 extern void netwm_init_rootwin(WRootWin *rw);
 
-extern WScreen *netwm_check_initial_fullscreen(WClientWin *cwin);
+extern bool netwm_check_initial_fullscreen(WClientWin *cwin);
 extern void netwm_update_state(WClientWin *cwin);
 extern void netwm_delete_state(WClientWin *cwin);
 extern void netwm_set_active(WRegion *reg);
