$NetBSD: patch-src_modules_perl_modperl_common_util.h,v 1.1 2013/11/14 17:03:41 adam Exp $

Don't inline functions when compiling with Clang. Fixes missing symbols issues.

--- src/modules/perl/modperl_common_util.h.orig	2013-11-14 16:46:44.000000000 +0000
+++ src/modules/perl/modperl_common_util.h
@@ -19,7 +19,7 @@
 #ifndef MODPERL_COMMON_UTIL_H
 #define MODPERL_COMMON_UTIL_H
 
-#ifdef MP_DEBUG
+#if defined(MP_DEBUG) || defined(__clang__)
 #define MP_INLINE
 #else
 #define MP_INLINE APR_INLINE
