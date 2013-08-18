$NetBSD: patch-src_base.h,v 1.1 2013/08/18 21:29:37 wiz Exp $

--- src/base.h.orig	2008-01-05 07:34:24.000000000 +0000
+++ src/base.h
@@ -1,12 +1,6 @@
 #ifndef __BASE_H
 #define __BASE_H
 
-#if ( __GNUC__ == 3 && __GNUC_MINOR__ > 0 ) || __GNUC__ > 3
-#define deprecated __attribute__((deprecated))
-#else
-#define deprecated
-#endif
-
 /*** Atomar Data Types ********************************************************/
 
 #ifdef NEED_BOOL
