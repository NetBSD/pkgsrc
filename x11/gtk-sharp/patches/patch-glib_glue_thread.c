$NetBSD: patch-glib_glue_thread.c,v 1.1 2012/05/03 06:03:30 wiz Exp $

Adapt for glib-2.32.

--- glib/glue/thread.c.orig	2009-01-07 16:54:06.000000000 +0000
+++ glib/glue/thread.c
@@ -20,7 +20,7 @@
  */
 
 
-#include <glib/gthread.h>
+#include <glib.h>
 
 gboolean glibsharp_g_thread_supported (void);
 
