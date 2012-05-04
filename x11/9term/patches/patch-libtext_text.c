$NetBSD: patch-libtext_text.c,v 1.1 2012/05/04 20:13:48 joerg Exp $

--- libtext/text.c.orig	1994-12-15 15:01:45.000000000 +0000
+++ libtext/text.c
@@ -4,7 +4,10 @@
 #include <frame.h>
 #include <text.h>
 
+#ifndef MAX
 #define MAX(x, y) ((x > y) ? x : y)
+#endif
+
 #define	BUTTON(n)	(1<<(n-1))
 
 static Menu	edit;
@@ -47,6 +50,7 @@ textalloc(Bitmap *b, Rectangle r, Font *
 		berror("textalloc: calloc");
 	t->length = 0;
 	t->base = 0;
+	t->end = 0;
 	t->p0 = 0;
 	t->p1 = 0;
 	t->pout = 0;
