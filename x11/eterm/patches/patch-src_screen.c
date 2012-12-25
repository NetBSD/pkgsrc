$NetBSD: patch-src_screen.c,v 1.1 2012/12/25 21:00:00 joerg Exp $

--- src/screen.c.orig	2012-12-25 16:03:55.000000000 +0000
+++ src/screen.c
@@ -104,8 +104,7 @@ encoding_t encoding_method = LATIN1;
 #endif
 
 /* Fill part/all of a drawn line with blanks. */
-inline void blank_line(text_t *, rend_t *, int, rend_t);
-inline void
+static void
 blank_line(text_t *et, rend_t *er, int width, rend_t efs)
 {
 /*    int             i = width; */
@@ -118,8 +117,7 @@ blank_line(text_t *et, rend_t *er, int w
 }
 
 /* Create a new row in the screen buffer and initialize it. */
-inline void blank_screen_mem(text_t **, rend_t **, int, rend_t);
-inline void
+static void
 blank_screen_mem(text_t **tp, rend_t **rp, int row, rend_t efs)
 {
     register unsigned int i = TERM_WINDOW_GET_REPORTED_COLS();
