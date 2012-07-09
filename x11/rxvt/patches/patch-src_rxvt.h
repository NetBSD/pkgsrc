$NetBSD: patch-src_rxvt.h,v 1.1 2012/07/09 19:06:22 joerg Exp $

--- src/rxvt.h.orig	2012-07-06 12:46:29.000000000 +0000
+++ src/rxvt.h
@@ -1097,8 +1097,9 @@ struct rxvt_hidden {
 #  if (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || (__GNUC__ < 2)
 #   define __attribute__(x)
 #  endif
-# endif
+# else
 # define __attribute__(x)
+# endif
 #endif
 
 /*
