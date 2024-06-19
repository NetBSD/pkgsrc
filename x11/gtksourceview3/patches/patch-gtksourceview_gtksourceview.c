$NetBSD: patch-gtksourceview_gtksourceview.c,v 1.1 2024/06/19 20:37:45 markd Exp $

gtksourceview.c: In function 'set_source_buffer':
gtksourceview.c:1589:43: error: assignment to 'GtkSourceBuffer *' {aka 'struct _GtkSourceBuffer *'}
  from incompatible pointer type 'GtkTextBuffer *' {aka 'struct _GtkTextBuffer *'} [-Wincompatible-pointer-types]

--- gtksourceview/gtksourceview.c.orig	2019-03-21 21:55:02.000000000 +0000
+++ gtksourceview/gtksourceview.c
@@ -1586,7 +1586,7 @@ set_source_buffer (GtkSourceView *view,
 	{
 		GtkSourceBufferInternal *buffer_internal;
 
-		view->priv->source_buffer = g_object_ref (buffer);
+		view->priv->source_buffer = g_object_ref (GTK_SOURCE_BUFFER (buffer));
 
 		g_signal_connect (buffer,
 				  "highlight-updated",
