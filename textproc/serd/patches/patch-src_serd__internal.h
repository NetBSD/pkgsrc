$NetBSD: patch-src_serd__internal.h,v 1.1 2015/04/27 14:11:26 jperkin Exp $

Fix _POSIX_C_SOURCE typo.

--- src/serd_internal.h.orig	2014-08-08 14:40:02.000000000 +0000
+++ src/serd_internal.h
@@ -17,7 +17,7 @@
 #ifndef SERD_INTERNAL_H
 #define SERD_INTERNAL_H
 
-#define _POSIX_C_SOURCE 201112L /* for posix_memalign and posix_fadvise */
+#define _POSIX_C_SOURCE 200112L /* for posix_memalign and posix_fadvise */
 
 #include <assert.h>
 #include <errno.h>
