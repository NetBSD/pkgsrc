$NetBSD: patch-src_compiler.h,v 1.1 2020/05/02 11:23:05 tnn Exp $

Conflicting type definition with libc popcount.

--- src/compiler.h.orig	2020-04-21 18:33:17.000000000 +0000
+++ src/compiler.h
@@ -111,6 +111,8 @@
 typedef unsigned long ulong;
 typedef unsigned int uint;
 
+#ifndef __NetBSD__
 static inline int popcount(uint x) {
 	return __builtin_popcount(x);
 }
+#endif
