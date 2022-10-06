$NetBSD: patch-config.m4,v 1.6 2022/10/06 14:28:43 taca Exp $

Allow build with enabling PKG_OPTIONS: maintainer-zts.

--- config.m4.orig	2021-10-07 08:47:52.000000000 +0000
+++ config.m4
@@ -127,6 +127,7 @@ if test "$PHP_APCU" != "no"; then
 			    AC_DEFINE(APC_NATIVE_RWLOCK, 1, [ ])
 			    AC_MSG_RESULT([yes])
 		    ],[ dnl -Failure-
+			    APCU_CFLAGS="-D_GNU_SOURCE -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"
 			    AC_MSG_RESULT([no])
     			PHP_APCU_RWLOCKS=no
 		    ],[
@@ -178,6 +179,7 @@ if test "$PHP_APCU" != "no"; then
 				  AC_MSG_RESULT([yes])
 				  AC_DEFINE(APC_HAS_PTHREAD_MUTEX, 1, [ ])
 			  ],[ dnl -Failure-
+				  APCU_CFLAGS="-D_GNU_SOURCE -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"
 				  AC_MSG_RESULT([no])
     			PHP_APCU_MUTEX=no
 			  ],[
