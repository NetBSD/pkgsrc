$NetBSD: patch-gtk_gtksearchenginesimple.c,v 1.1 2017/05/23 15:35:21 jperkin Exp $

Don't define _XOPEN_SOURCE on SunOS when using >= C99.

--- gtk/gtksearchenginesimple.c.orig	2015-12-28 15:42:28.000000000 +0000
+++ gtk/gtksearchenginesimple.c
@@ -27,7 +27,9 @@
  * export ftw() and friends only if _XOPEN_SOURCE and _GNU_SOURCE
  * are defined. see bug #444097.
  */
+#if !defined(__sun) || __STDC_VERSION__ - 0 < 199901L
 #define _XOPEN_SOURCE 500
+#endif
 #define _GNU_SOURCE 
 
 #ifdef HAVE_FTW_H
