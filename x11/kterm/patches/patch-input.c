$NetBSD: patch-input.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- input.c.orig	2013-03-01 13:15:13.000000000 +0000
+++ input.c
@@ -64,11 +64,7 @@ register TScreen *screen;
 	}
 }
 
-Input (keyboard, screen, event, eightbit)
-    register TKeyboard	*keyboard;
-    register TScreen	*screen;
-    register XKeyEvent *event;
-    Bool eightbit;
+void Input (TKeyboard *keyboard, TScreen *screen, XKeyEvent *event, Bool eightbit)
 {
 
 #ifdef KTERM
