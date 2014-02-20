$NetBSD: patch-media_libpng_pngpriv.h,v 1.4 2014/02/20 13:19:03 ryoon Exp $

--- media/libpng/pngpriv.h.orig	2014-02-12 21:29:13.000000000 +0000
+++ media/libpng/pngpriv.h
@@ -38,6 +38,7 @@
  * still required (as of 2011-05-02.)
  */
 #define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#define _XOPEN_SOURCE 600
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* Standard library headers not required by png.h: */
