$NetBSD: patch-gtk_gtksearchenginesimple.c,v 1.1 2012/03/21 19:58:47 hans Exp $

--- gtk/gtksearchenginesimple.c.orig	2011-12-19 14:58:28.000000000 +0100
+++ gtk/gtksearchenginesimple.c	2012-03-21 20:36:33.118910490 +0100
@@ -27,7 +27,9 @@
  * export ftw() and friends only if _XOPEN_SOURCE and _GNU_SOURCE
  * are defined. see bug #444097.
  */
+#ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 500
+#endif
 #define _GNU_SOURCE 
 
 #ifdef HAVE_FTW_H
