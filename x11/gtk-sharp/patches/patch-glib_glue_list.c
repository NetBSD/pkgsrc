$NetBSD: patch-glib_glue_list.c,v 1.1 2012/05/03 06:03:30 wiz Exp $

Adapt for glib-2.32.

--- glib/glue/list.c.orig	2009-01-07 16:54:06.000000000 +0000
+++ glib/glue/list.c
@@ -20,7 +20,7 @@
  */
 
 
-#include <glib/glist.h>
+#include <glib.h>
 
 /* Forward declarations */
 gpointer gtksharp_list_get_data (GList *l);
