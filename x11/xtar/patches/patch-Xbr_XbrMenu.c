$NetBSD: patch-Xbr_XbrMenu.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- Xbr/XbrMenu.c.orig	1995-05-09 08:06:47.000000000 +0000
+++ Xbr/XbrMenu.c
@@ -18,6 +18,7 @@
  *
  */
 
+#include <stdlib.h>
 #include <Xm/Xm.h>
 #include <Xm/CascadeB.h>
 #include <Xm/Label.h>
