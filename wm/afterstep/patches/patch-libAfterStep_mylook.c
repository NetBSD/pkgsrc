$NetBSD: patch-libAfterStep_mylook.c,v 1.2 2016/05/01 19:30:58 dholland Exp $

Patch up gcc inline mess.

--- libAfterStep/mylook.c.orig	2012-05-04 14:35:51.000000000 +0000
+++ libAfterStep/mylook.c
@@ -813,7 +813,7 @@ mylook_get_style(MyLook *look, const cha
     return NULL;
 }
 
-inline MyDesktopConfig *
+MyDesktopConfig *
 mylook_get_desk_config(MyLook *look, long desk)
 {
     if( look )
@@ -827,7 +827,7 @@ mylook_get_desk_config(MyLook *look, lon
 }
 
 
-inline MyBackground *
+MyBackground *
 mylook_get_desk_back(MyLook *look, long desk)
 {
 	MyBackground *myback = NULL ;
