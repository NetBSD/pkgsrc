$NetBSD: patch-glib_glue_slist.c,v 1.1 2012/05/03 06:03:30 wiz Exp $

Adapt for glib-2.32.

--- glib/glue/slist.c.orig	2009-01-07 16:54:06.000000000 +0000
+++ glib/glue/slist.c
@@ -20,7 +20,7 @@
  */
 
 
-#include <glib/gslist.h>
+#include <glib.h>
 
 /* Forward declarations */
 gpointer gtksharp_slist_get_data (GSList *l);
