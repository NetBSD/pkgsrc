$NetBSD: patch-fm.h,v 1.2 2026/01/17 22:35:59 wiz Exp $

Include strings.h for bcopy().

--- fm.h.orig	2025-08-20 09:32:27.000000000 +0000
+++ fm.h
@@ -77,9 +77,7 @@
 #include "terms.h"
 #include "istream.h"
 
-#ifdef __EMX__
 #include <strings.h>		/* for bzero() and bcopy() */
-#endif
 
 #ifdef MAINPROGRAM
 #define global
