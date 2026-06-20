$NetBSD: patch-manage.c,v 1.1 2026/06/20 10:40:33 nia Exp $

Fix implicit declaration of strcmp(3).

--- manage.c.orig	2026-06-20 10:38:10.416103877 +0000
+++ manage.c
@@ -1,6 +1,7 @@
 /* Copyright (c) 1994 David Hogan, 2000 Benjamin Drieu, see README for licence details */
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <X11/X.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
