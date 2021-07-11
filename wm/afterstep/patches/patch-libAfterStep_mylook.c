$NetBSD: patch-libAfterStep_mylook.c,v 1.3 2021/07/11 12:13:17 bsiegert Exp $

Patch up gcc inline mess.

--- libAfterStep/mylook.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/mylook.c
@@ -843,7 +843,7 @@ MyStyle *mylook_get_style (MyLook * look
 	return NULL;
 }
 
-inline MyDesktopConfig *mylook_get_desk_config (MyLook * look, long desk)
+MyDesktopConfig *mylook_get_desk_config (MyLook * look, long desk)
 {
 	if (look) {
 		ASHashData hdata = { 0 };
@@ -856,7 +856,7 @@ inline MyDesktopConfig *mylook_get_desk_
 }
 
 
-inline MyBackground *mylook_get_desk_back (MyLook * look, long desk)
+MyBackground *mylook_get_desk_back (MyLook * look, long desk)
 {
 	MyBackground *myback = NULL;
 
