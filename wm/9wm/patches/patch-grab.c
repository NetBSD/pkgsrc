$NetBSD: patch-grab.c,v 1.1 2022/05/18 19:48:23 nikita Exp $

Fix warnings related to select().

--- grab.c.orig	2022-05-18 21:37:30.561383566 +0200
+++ grab.c	2022-05-18 21:38:11.578614585 +0200
@@ -2,6 +2,7 @@
  * Copyright multiple authors, see README for licence details
  */
 #include <stdio.h>
+#include <sys/select.h>
 #include <X11/X.h>
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
