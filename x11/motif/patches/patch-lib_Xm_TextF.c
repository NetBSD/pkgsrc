$NetBSD: patch-lib_Xm_TextF.c,v 1.1 2012/11/10 17:10:10 ryoon Exp $

--- lib/Xm/TextF.c.orig	2012-10-22 14:50:34.000000000 +0000
+++ lib/Xm/TextF.c
@@ -86,11 +86,11 @@ static char rcsid[] = "$TOG: TextF.c /ma
 #define FIX_1409
 
 #if (defined(__FreeBSD__) && (__FreeBSD__ < 4)) || \
-    (defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__))
+    (defined(__APPLE__) || defined(__OpenBSD__))
 /*
  * Modification by Integrated Computer Solutions, Inc.  May 2000
  *
- * FreeBSD (pre-4.0), DARWIN, NetBSD, and OpenBSD do not include the necessary
+ * FreeBSD (pre-4.0), DARWIN, NetBSD before 1.6, and OpenBSD do not include the necessary
  * wide character string functions.  Use the internal _Xwc... routines and add
  * the other missing functions as _Xmwc... routines.  The new functions are
  * added static to this file.
