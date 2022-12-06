$NetBSD: patch-xlax.h,v 1.1 2022/12/06 21:04:14 vins Exp $

Avoid redefinitions.

--- xlax.h.orig	2008-07-31 20:18:25.000000000 +0000
+++ xlax.h
@@ -39,8 +39,12 @@
 #include <X11/Xmu/WinUtil.h>
 
 #include <X11/cursorfont.h>
+#ifndef XK_MISCELLANY
 #define XK_MISCELLANY  1
+#endif
+#ifndef XK_LATIN1
 #define XK_LATIN1  1
+#endif
 #include <X11/keysymdef.h>
 
 #include <stdlib.h>
