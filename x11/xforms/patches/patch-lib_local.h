$NetBSD: patch-lib_local.h,v 1.1 2012/12/19 14:25:56 jperkin Exp $

Use strerror() on 64-bit Solaris.

--- lib/local.h.orig	2012-12-19 14:21:49.065051486 +0000
+++ lib/local.h	2012-12-19 14:22:17.622101606 +0000
@@ -81,7 +81,7 @@
 
 /* (some) suns do not have strerror, use sys_errlist */
 
-#if ( defined(sun) || defined(__sun__) ) && !defined( SYSV )
+#if ( defined(sun) || defined(__sun__) ) && !defined( SYSV ) && !defined(_LP64)
 #define DONT_HAVE_STRERROR
 #define DONT_HAVE_ATEXIT
 #define BAD_SPRINTF		/* returns char * */
