$NetBSD: patch-button.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- button.c.orig	2013-03-01 13:08:51.000000000 +0000
+++ button.c
@@ -32,6 +32,7 @@ button.c	Handles button events in the te
 
 #include "ptyx.h"		/* Xlib headers included here. */
 #include <X11/Xatom.h>
+#include <stdlib.h>
 #include <stdio.h>
 
 #include <X11/Xmu/Atoms.h>
@@ -41,7 +42,7 @@ button.c	Handles button events in the te
 #include "error.h"
 #include "menu.h"
 
-extern char *malloc();
+void TrackText(int frow, int fcol, int trow, int tcol);
 
 extern void DoSecureKeyboard();
 
@@ -1368,8 +1369,7 @@ register Bchr *ptr;
 
 #endif	/* KTERM && KTERM_MBCC */
 
-TrackText(frow, fcol, trow, tcol)
-    register int frow, fcol, trow, tcol;
+void TrackText(int frow, int fcol, int trow, int tcol)
     /* Guaranteed (frow, fcol) <= (trow, tcol) */
 {
 	register int from, to;
