$NetBSD: patch-m4_sxe-compiler.m4,v 1.4 2019/03/03 02:30:28 schmonz Exp $

Don't create broken or non-portable binaries. This code isn't even
performance critical.

--- m4/sxe-compiler.m4.orig	2018-03-01 09:55:48.000000000 +0000
+++ m4/sxe-compiler.m4
@@ -446,9 +446,6 @@ AC_DEFUN([SXE_FEATFLAGS], [dnl
 	SXE_CHECK_COMPILER_FLAG([-static-intel], [
 		featflags="${featflags} -static-intel"
 		XCCLDFLAGS="${XCCLDFLAGS} \${XCCFLAG} -static-intel"], [:])
-	SXE_CHECK_COMPILER_FLAG([-static-libgcc], [
-		featflags="${featflags} -static-libgcc"
-		XCCLDFLAGS="${XCCLDFLAGS} \${XCCFLAG} -static-libgcc"], [:])
 
 	SXE_CHECK_COMPILER_FLAG([-intel-extensions], [dnl
 		featflags="${featflags} -intel-extensions"])
@@ -501,7 +498,6 @@ dnl + native[=yes|no]  Emit the --enable
 	## Use either command line flag, environment var, or autodetection
 	SXE_DEBUGFLAGS
 	SXE_WARNFLAGS
-	SXE_OPTIFLAGS
 	m4_foreach_w([opt], [$1], [dnl
 		m4_case(opt,
 			[native], [SXE_CC_NATIVE],
