$NetBSD: patch-config.m4,v 1.2 2016/08/11 23:11:25 jdolecek Exp $

Fix bashism.

--- config.m4.orig	2016-04-20 11:38:56.000000000 +0000
+++ config.m4
@@ -157,7 +157,7 @@ if test "$PHP_APCU" != "no"; then
 		fi
 	fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
     orig_LIBS="$LIBS"
 	  LIBS="$LIBS -lpthread"
 	  AC_TRY_RUN(
@@ -210,8 +210,8 @@ if test "$PHP_APCU" != "no"; then
 	  LIBS="$orig_LIBS"
   fi
   
-  if test "$PHP_APCU_RWLOCKS" == "no"; then
-   if test "$PHP_APCU_MUTEX" == "no"; then
+  if test "$PHP_APCU_RWLOCKS" = "no"; then
+   if test "$PHP_APCU_MUTEX" = "no"; then
     if test "$PHP_APCU_SPINLOCK" != "no"; then
       AC_DEFINE(APC_SPIN_LOCK, 1, [ ])
       AC_MSG_WARN([APCu spin locking enabled])
