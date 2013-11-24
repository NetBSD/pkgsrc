$NetBSD: patch-button.c,v 1.1 2013/11/24 05:53:52 dholland Exp $

- use standard headers
- don't declare own malloc

--- button.c~	2001-06-06 13:05:15.000000000 +0000
+++ button.c
@@ -31,6 +31,7 @@ button.c	Handles button events in the te
 #include "ptyx.h"		/* Xlib headers included here. */
 #include <X11/Xatom.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 #include <X11/Xmu/Atoms.h>
 #include <X11/Xmu/StdSel.h>
@@ -42,8 +43,6 @@ button.c	Handles button events in the te
 
 void TrackText();
 
-extern char *malloc();
-
 extern void input_to_chat();
 extern void HideCursor();
 extern void DoSecureKeyboard();
