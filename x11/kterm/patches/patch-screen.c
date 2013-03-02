$NetBSD: patch-screen.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- screen.c.orig	2013-03-01 13:18:30.000000000 +0000
+++ screen.c
@@ -246,24 +246,14 @@ Reallocate(sbuf, sbufaddr, nrow, ncol, o
 }
 
 #ifdef KTERM
-ScreenWrite (screen, str, flags, gset, length)
+void ScreenWrite (TScreen *screen, Char *str, unsigned flags, Char gset, int length)
 #else /* !KTERM */
-ScreenWrite (screen, str, flags, length)
+void ScreenWrite (TScreen *screen, char *str, unsigned flags, int length)
 #endif /* !KTERM */
 /*
    Writes str into buf at row row and column col.  Characters are set to match
    flags.
  */
-TScreen *screen;
-#ifdef KTERM
-Char *str;
-register unsigned flags;
-register Char gset;
-#else /* !KTERM */
-char *str;
-register unsigned flags;
-#endif /* !KTERM */
-register int length;		/* length of string */
 {
 #ifdef KTERM
 	register int avail  = screen->max_col - screen->cur_col + 1;
