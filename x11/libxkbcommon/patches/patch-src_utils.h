$NetBSD: patch-src_utils.h,v 1.1 2016/11/14 14:08:17 wiz Exp $

Fix conflict with NetBSD's popcount.
https://github.com/xkbcommon/libxkbcommon/issues/41

--- src/utils.h.orig	2016-10-31 11:19:02.000000000 +0000
+++ src/utils.h
@@ -179,7 +179,7 @@ msb_pos(uint32_t mask)
 }
 
 static inline int
-popcount(uint32_t x)
+popcountu(uint32_t x)
 {
     int count;
 #if defined(HAVE___BUILTIN_POPCOUNT)
