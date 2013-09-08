$NetBSD: patch-acinclude.m4,v 1.1 2013/09/08 07:23:56 ryoon Exp $

* Fix build under OS X 10.8.4 with clang.
  http://bugs.motifzone.net/show_bug.cgi?id=1625

--- acinclude.m4.orig	2012-10-22 14:50:39.000000000 +0000
+++ acinclude.m4
@@ -3,6 +3,7 @@ dnl This file provides the following mac
 dnl
 dnl     LT_LIB_XTHREADS
 dnl	AM_FUNC_VOID_SPRINTF
+dnl	WEAK_ALIAS_SUPPORT
 dnl
 
 dnl This should be the canonical approach to check for XTHREADS.
@@ -57,6 +58,22 @@ if test $ac_cv_func_void_sprintf = no; t
 fi
 ])
 
+dnl This tests whether weak aliases are supported.
+AC_DEFUN([WEAK_ALIAS_SUPPORT],
+[AC_CACHE_CHECK(whether weak aliases are supported, ac_cv_weak_alias_support,
+[AC_TRY_COMPILE([
+int get_value(int *value) {
+  return *value;
+}
+int get_value_alias(int *high) __attribute__((__weak__,alias("get_value")));
+],
+[],
+ac_cv_weak_alias_support=yes,
+ac_cv_weak_alias_support=no)])
+if test $ac_cv_weak_alias_support = no; then
+  AC_DEFINE(NO_WEAK_ALIASES,1,[Define if weak aliases are not supported])
+fi
+])
 
 dnl
 dnl End of special macros.
