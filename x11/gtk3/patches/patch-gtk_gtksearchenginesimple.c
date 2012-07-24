$NetBSD: patch-gtk_gtksearchenginesimple.c,v 1.2 2012/07/24 18:27:41 drochner Exp $

--- gtk/gtksearchenginesimple.c.orig	2012-07-15 16:58:25.000000000 +0000
+++ gtk/gtksearchenginesimple.c
@@ -26,7 +26,9 @@
  * export ftw() and friends only if _XOPEN_SOURCE and _GNU_SOURCE
  * are defined. see bug #444097.
  */
+#ifndef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 600
+#endif
 #define _GNU_SOURCE
 
 #ifdef HAVE_FTW_H
