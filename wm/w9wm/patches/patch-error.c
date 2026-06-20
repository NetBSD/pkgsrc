$NetBSD: patch-error.c,v 1.1 2026/06/20 10:40:32 nia Exp $

Fix implicit declaration of exit(3).

--- error.c.orig	2026-06-20 10:38:22.997156686 +0000
+++ error.c
@@ -1,5 +1,6 @@
 /* Copyright (c) 1994 David Hogan, see README for licence details */
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
