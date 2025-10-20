$NetBSD: patch-src_feature.h,v 1.1 2025/10/20 18:32:10 vins Exp $

pkgsrc PREFIX support.

--- src/feature.h.orig	2002-04-09 00:49:38.000000000 +0000
+++ src/feature.h
@@ -25,7 +25,7 @@
 #define _FEATURE_H
 
 #ifndef X11USRLIBDIR
-# define X11USRLIBDIR		"/usr/X11R6/lib"
+# define X11USRLIBDIR		"@PREFIX@/lib"
 #endif
 #ifndef X11LIBDIR
 # define X11LIBDIR		X11USRLIBDIR "/X11"
