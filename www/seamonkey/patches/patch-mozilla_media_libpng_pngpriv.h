$NetBSD: patch-mozilla_media_libpng_pngpriv.h,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/media/libpng/pngpriv.h.orig	2013-08-04 03:05:41.000000000 +0000
+++ mozilla/media/libpng/pngpriv.h
@@ -38,6 +38,7 @@
  * still required (as of 2011-05-02.)
  */
 #define _POSIX_SOURCE 1 /* Just the POSIX 1003.1 and C89 APIs */
+#define _XOPEN_SOURCE 600
 
 #ifndef PNG_VERSION_INFO_ONLY
 /* This is required for the definition of abort(), used as a last ditch
