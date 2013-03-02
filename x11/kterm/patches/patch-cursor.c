$NetBSD: patch-cursor.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- cursor.c.orig	2013-03-01 13:14:01.000000000 +0000
+++ cursor.c
@@ -162,9 +162,7 @@ int		n;
  * Moves cursor down amount lines, scrolls if necessary.
  * Won't leave scrolling region. No carriage return.
  */
-Index(screen, amount)
-register TScreen	*screen;
-register int	amount;
+void Index(TScreen *screen, int amount)
 {
 	register int j;
 
@@ -186,9 +184,7 @@ register int	amount;
  * Moves cursor up amount lines, reverse scrolls if necessary.
  * Won't leave scrolling region. No carriage return.
  */
-RevIndex(screen, amount)
-register TScreen	*screen;
-register int	amount;
+void RevIndex(TScreen *screen, int amount)
 {
 	/*
 	 * reverse indexing when above scrolling region is cursor up.
