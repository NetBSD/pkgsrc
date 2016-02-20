$NetBSD: patch-src_noteedit.c,v 1.1 2016/02/20 16:00:28 khorben Exp $

Fix build with Gtk+ 2

--- src/noteedit.c.orig	2016-02-20 15:45:01.000000000 +0000
+++ src/noteedit.c
@@ -31,6 +31,7 @@
 #include <stdlib.h>
 #include <libintl.h>
 #include <gtk/gtk.h>
+#include <Desktop.h>
 #include "noteedit.h"
 #define _(string) gettext(string)
 
