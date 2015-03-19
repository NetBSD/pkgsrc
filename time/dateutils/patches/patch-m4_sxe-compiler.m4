$NetBSD: patch-m4_sxe-compiler.m4,v 1.1 2015/03/19 19:17:18 joerg Exp $

Don't create broken or non-portable binaries. This code isn't even
performance critical.

--- m4/sxe-compiler.m4.orig	2015-03-19 00:06:56.000000000 +0000
+++ m4/sxe-compiler.m4
@@ -453,7 +453,6 @@ AC_DEFUN([SXE_CHECK_CFLAGS], [dnl
 	## Use either command line flag, environment var, or autodetection
 	SXE_DEBUGFLAGS
 	SXE_WARNFLAGS
-	SXE_OPTIFLAGS
 	SXE_CFLAGS="${SXE_CFLAGS} ${debugflags} ${optiflags} ${warnflags}"
 
 	SXE_FEATFLAGS
