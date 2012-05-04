$NetBSD: patch-libAfterStep_mylook.h,v 1.1 2012/05/04 16:36:11 joerg Exp $

--- libAfterStep/mylook.h.orig	2012-05-04 14:35:54.000000000 +0000
+++ libAfterStep/mylook.h
@@ -401,9 +401,9 @@ void mylook_destroy (MyLook ** look);
 
 
 struct MyStyle *mylook_get_style(MyLook *look, const char *name);
-inline MyBackground  *mylook_get_desk_back(MyLook *look, long desk);
-inline MyBackground  *mylook_get_back(MyLook *look, char *name);
-inline MyDesktopConfig *mylook_get_desk_config(MyLook *look, long desk);
+MyBackground  *mylook_get_desk_back(MyLook *look, long desk);
+MyBackground  *mylook_get_back(MyLook *look, char *name);
+MyDesktopConfig *mylook_get_desk_config(MyLook *look, long desk);
 
 
 
