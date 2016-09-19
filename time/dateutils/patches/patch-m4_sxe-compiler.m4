$NetBSD: patch-m4_sxe-compiler.m4,v 1.3 2016/09/19 05:33:15 mef Exp $

Don't create broken or non-portable binaries. This code isn't even
performance critical.

--- m4/sxe-compiler.m4~	2016-05-20 17:25:12.000000000 +0900
+++ m4/sxe-compiler.m4	2016-09-19 14:25:55.000000000 +0900
@@ -501,7 +501,6 @@ dnl + native[=yes|no]  Emit the --enable
 	## Use either command line flag, environment var, or autodetection
 	SXE_DEBUGFLAGS
 	SXE_WARNFLAGS
-	SXE_OPTIFLAGS
 	m4_foreach_w([opt], [$1], [dnl
 		m4_case(opt,
 			[native], [SXE_CC_NATIVE],
