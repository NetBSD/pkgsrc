$NetBSD: patch-config.m4,v 1.7 2023/11/30 16:31:21 taca Exp $

Allow build with enabling PKG_OPTIONS: maintainer-zts.

--- config.m4.orig	2023-11-11 17:35:28.000000000 +0000
+++ config.m4
@@ -127,6 +127,7 @@ if test "$PHP_APCU" != "no"; then
           AC_DEFINE(APC_NATIVE_RWLOCK, 1, [ ])
           AC_MSG_RESULT([yes])
         ],[ dnl -Failure-
+	  APCU_CFLAGS="-D_GNU_SOURCE -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"
           AC_MSG_RESULT([no])
           PHP_APCU_RWLOCKS=no
         ],[
@@ -178,6 +179,7 @@ if test "$PHP_APCU" != "no"; then
           AC_MSG_RESULT([yes])
           AC_DEFINE(APC_HAS_PTHREAD_MUTEX, 1, [ ])
         ],[ dnl -Failure-
+	  APCU_CFLAGS="-D_GNU_SOURCE -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1"
           AC_MSG_RESULT([no])
           PHP_APCU_MUTEX=no
         ],[
