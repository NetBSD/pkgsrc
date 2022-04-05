$NetBSD: patch-src_widget.cc,v 1.2 2022/04/05 15:51:58 jperkin Exp $

Provide W_EXITCODE compat.

--- src/widget.cc.orig	2022-03-27 17:52:19.000000000 +0000
+++ src/widget.cc
@@ -22,6 +22,10 @@
 
 #include <sys/wait.h> // for W_EXITCODE
 
+#ifndef W_EXITCODE
+#define W_EXITCODE(ret, sig)	((ret) << 8 | (sig))
+#endif
+
 #include <exception>
 #include <new>
 #include <stdexcept>
