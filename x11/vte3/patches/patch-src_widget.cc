$NetBSD: patch-src_widget.cc,v 1.1 2019/03/27 11:19:10 jperkin Exp $

Provide W_EXITCODE compat.

--- src/widget.cc.orig	2018-12-10 21:32:09.000000000 +0000
+++ src/widget.cc
@@ -22,6 +22,10 @@
 
 #include <sys/wait.h> // for W_EXITCODE
 
+#ifndef W_EXITCODE
+#define W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
+#endif
+
 #include <new>
 #include <string>
 
