$NetBSD: patch-gtksourceview_gtksourceview.h,v 1.1 2012/08/31 19:43:49 prlw1 Exp $

Continuation lines not parsed correctly in enum.

--- gtksourceview/gtksourceview.h.orig	2011-09-12 13:03:15.000000000 +0000
+++ gtksourceview/gtksourceview.h
@@ -130,13 +130,7 @@ typedef enum
 	GTK_SOURCE_DRAW_SPACES_LEADING    = 1 << 4,
 	GTK_SOURCE_DRAW_SPACES_TEXT       = 1 << 5,
 	GTK_SOURCE_DRAW_SPACES_TRAILING   = 1 << 6,
-	GTK_SOURCE_DRAW_SPACES_ALL        = (GTK_SOURCE_DRAW_SPACES_SPACE   | \
-	                                     GTK_SOURCE_DRAW_SPACES_TAB     | \
-	                                     GTK_SOURCE_DRAW_SPACES_NEWLINE | \
-	                                     GTK_SOURCE_DRAW_SPACES_NBSP | \
-	                                     GTK_SOURCE_DRAW_SPACES_LEADING | \
-	                                     GTK_SOURCE_DRAW_SPACES_TEXT | \
-	                                     GTK_SOURCE_DRAW_SPACES_TRAILING)
+	GTK_SOURCE_DRAW_SPACES_ALL        = (GTK_SOURCE_DRAW_SPACES_SPACE   | GTK_SOURCE_DRAW_SPACES_TAB | GTK_SOURCE_DRAW_SPACES_NEWLINE | GTK_SOURCE_DRAW_SPACES_NBSP | GTK_SOURCE_DRAW_SPACES_LEADING | GTK_SOURCE_DRAW_SPACES_TEXT | GTK_SOURCE_DRAW_SPACES_TRAILING)
 } GtkSourceDrawSpacesFlags;
 
 
