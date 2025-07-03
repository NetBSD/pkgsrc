$NetBSD: patch-fm.h,v 1.1 2025/07/03 10:50:37 jperkin Exp $

Include strings.h for bcopy().

--- fm.h.orig	2025-07-03 10:47:28.078773140 +0000
+++ fm.h
@@ -83,9 +83,7 @@ typedef int wc_ces;	/* XXX: not used */
 void bcopy(const void *, void *, int);
 void bzero(void *, int);
 #endif				/* HAVE_BCOPY */
-#ifdef __EMX__
 #include <strings.h>		/* for bzero() and bcopy() */
-#endif
 
 #ifdef MAINPROGRAM
 #define global
