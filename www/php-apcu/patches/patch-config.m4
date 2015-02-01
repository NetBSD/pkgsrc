$NetBSD: patch-config.m4,v 1.1 2015/02/01 08:11:20 taca Exp $

Fix bashism.

--- config.m4.orig	2014-10-11 17:02:21.000000000 +0000
+++ config.m4
@@ -140,7 +140,7 @@ if test "$PHP_APCU" != "no"; then
     LIBS="$orig_LIBS"
   fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
     orig_LIBS="$LIBS"
 	  LIBS="$LIBS -lpthread"
 	  AC_TRY_RUN(
@@ -193,8 +193,8 @@ if test "$PHP_APCU" != "no"; then
 	  LIBS="$orig_LIBS"
   fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
-   if test "$PHP_APCU_MUTEX" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
+   if test "$PHP_APCU_MUTEX" = "no"; then
     if test "$PHP_APCU_SPINLOCK" != "no"; then
       AC_DEFINE(APC_SPIN_LOCK, 1, [ ])
       AC_MSG_WARN([APCu spin locking enabled])
