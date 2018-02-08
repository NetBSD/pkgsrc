$NetBSD: patch-config.m4,v 1.4 2018/02/08 22:15:12 jdolecek Exp $

Fix bashism. Reported upstream as #75791.

Reported also as GH#274 - https://github.com/krakjoe/apcu/issues/274

--- config.m4.orig	2016-06-07 12:41:02.000000000 +0000
+++ config.m4
@@ -149,7 +149,7 @@ if test "$PHP_APCU" != "no"; then
 		fi
 	fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
     orig_LIBS="$LIBS"
 	  LIBS="$LIBS -lpthread"
 	  AC_TRY_RUN(
@@ -202,8 +202,8 @@ if test "$PHP_APCU" != "no"; then
 	  LIBS="$orig_LIBS"
   fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
-   if test "$PHP_APCU_MUTEX" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
+   if test "$PHP_APCU_MUTEX" = "no"; then
     if test "$PHP_APCU_SPINLOCK" != "no"; then
       AC_DEFINE(APC_SPIN_LOCK, 1, [ ])
       AC_MSG_WARN([APCu spin locking enabled])
