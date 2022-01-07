$NetBSD: patch-Xbr_XbrGfx.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- Xbr/XbrGfx.c.orig	1995-05-09 08:06:47.000000000 +0000
+++ Xbr/XbrGfx.c
@@ -46,6 +46,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <math.h>
 #include <ctype.h>
