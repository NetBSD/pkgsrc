$NetBSD: patch-pTK_Lang.h,v 1.1 2014/05/31 09:54:23 tron Exp $

Fix build with Perl 5.20.0 and newer.

--- pTk/Lang.h.orig	2010-05-29 10:56:05.000000000 +0100
+++ pTk/Lang.h	2014-05-31 10:50:03.000000000 +0100
@@ -4,10 +4,6 @@
 #define STATIC_BUILD
 
 
-#ifdef bool
-#undef bool
-#endif
-
 #include "tkConfig.h"
 #define TCL_NO_DEPRECATED
 
