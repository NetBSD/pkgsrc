$NetBSD: patch-wxc_src_ewxw_eljtoolbar.cpp,v 1.1 2015/02/20 23:39:31 joerg Exp $

--- wxc/src/ewxw/eljtoolbar.cpp.orig	2015-02-20 23:10:53.000000000 +0000
+++ wxc/src/ewxw/eljtoolbar.cpp
@@ -15,7 +15,7 @@ EWXWEXPORT(void, wxToolBar_Delete) (void
 
 EWXWEXPORT(int, wxToolBar_AddControl) (void* _obj, void* ctrl)
 {
-	return (int)((wxToolBar*)_obj)->AddControl ((wxControl*)ctrl);
+	return (int)(intptr_t)((wxToolBar*)_obj)->AddControl ((wxControl*)ctrl);
 }
 
 EWXWEXPORT(void, wxToolBar_AddSeparator) (void* _obj)
