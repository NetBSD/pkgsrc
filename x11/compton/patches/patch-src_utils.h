$NetBSD: patch-src_utils.h,v 1.1 2019/09/17 11:43:29 tnn Exp $

Use libc popcountl if present.

--- src/utils.h.orig	2019-08-18 21:40:33.000000000 +0000
+++ src/utils.h
@@ -114,9 +114,11 @@ static inline int attr_const normalize_i
 /// clamp `val` into interval [min, max]
 #define clamp(val, min, max) max2(min2(val, max), min)
 
+#ifndef HAS_POPCOUNTL
 static inline int attr_const popcountl(unsigned long a) {
 	return __builtin_popcountl(a);
 }
+#endif
 
 /**
  * Normalize a double value to a specific range.
