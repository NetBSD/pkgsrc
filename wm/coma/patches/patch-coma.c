$NetBSD: patch-coma.c,v 1.1 2022/12/19 13:57:34 vins Exp $

Portability fix for SunOS.

--- coma.c.orig	2019-08-21 12:39:43.000000000 +0000
+++ coma.c
@@ -29,6 +29,10 @@
 
 #include "coma.h"
 
+#ifdef __sun
+#define WAIT_ANY        (-1)
+#endif
+
 static void	coma_signal(int);
 
 char			myhost[256];
