$NetBSD: patch-lib_contrib_gnome-languages.c,v 1.1 2020/01/21 15:02:08 nia Exp $

NetBSD does not have uselocale yet.

--- lib/contrib/gnome-languages.c.orig	2019-11-22 21:24:16.000000000 +0000
+++ lib/contrib/gnome-languages.c
@@ -51,6 +51,10 @@
 #include "default-input-sources.h"
 #endif
 
+#ifdef __NetBSD__
+#define uselocale(v) (NULL)
+#endif
+
 typedef struct _GnomeLocale {
         char *id;
         char *name;
