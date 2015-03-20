$NetBSD: patch-js_src_dtoa.c,v 1.1 2015/03/20 10:13:57 martin Exp $

Fix Bug 1111395

--- js/src/dtoa.c.orig	2015-03-20 10:50:05.000000000 +0100
+++ js/src/dtoa.c	2015-03-20 10:53:36.000000000 +0100
@@ -3246,3 +3246,5 @@
 		*rve = s;
 	return s0;
 	}
+#undef CONST
+
