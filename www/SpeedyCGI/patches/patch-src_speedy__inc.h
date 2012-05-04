$NetBSD: patch-src_speedy__inc.h,v 1.1 2012/05/04 16:37:19 joerg Exp $

--- src/speedy_inc.h.orig	2012-05-04 14:07:56.000000000 +0000
+++ src/speedy_inc.h
@@ -41,11 +41,7 @@ typedef long long speedy_ino_t;
 #   define MAP_FAILED (-1)
 #endif
 
-#ifdef __GNUC__
-#define SPEEDY_INLINE __inline__
-#else
 #define SPEEDY_INLINE
-#endif
 
 #ifdef EWOULDBLOCK
 #   define SP_EWOULDBLOCK(e) ((e) == EWOULDBLOCK)
