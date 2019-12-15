$NetBSD: patch-src_utils.h,v 1.1 2019/12/15 14:05:47 nia Exp $

Conflicting type definition with libc popcountl

--- src/utils.h.orig	2019-11-18 21:59:30.000000000 +0000
+++ src/utils.h
@@ -114,9 +114,11 @@ static inline int attr_const normalize_i
 /// clamp `val` into interval [min, max]
 #define clamp(val, min, max) max2(min2(val, max), min)
 
+#ifndef __NetBSD__
 static inline int attr_const popcountl(unsigned long a) {
 	return __builtin_popcountl(a);
 }
+#endif
 
 /**
  * Normalize a double value to a specific range.
