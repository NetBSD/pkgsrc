$NetBSD: patch-dclock.c,v 1.1 2026/06/20 01:17:05 nia Exp $

Fix implicit declaration of exit(3) and implicit int,
which recent GCC no longer likes.

--- dclock.c.orig	2026-06-20 01:13:24.148057716 +0000
+++ dclock.c
@@ -19,6 +19,7 @@
  * manager: *Dclock.seconds: on
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include "Dclock.h"
 
@@ -82,7 +83,9 @@ static XtActionsRec actionsList[] = {
     { "quit",	quit },
 };
 
+int
 main(argc, argv)
+int argc;
 char *argv[];
 {
     Widget toplevel, clock_w;
