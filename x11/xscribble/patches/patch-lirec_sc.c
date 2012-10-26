$NetBSD: patch-lirec_sc.c,v 1.1 2012/10/26 20:14:51 joerg Exp $

--- lirec/sc.c.orig	2012-10-26 14:07:40.000000000 +0000
+++ lirec/sc.c
@@ -26,10 +26,13 @@ Software Foundation, Inc., 675 Mass Ave,
 #include "matrix.h"
 #include "util.h"
 #include "sc.h"
-#include "stdio.h"
+#include <stdio.h>
+#include <stdlib.h>
 #include "math.h"
 #include "zdebug.h"
 
+static void FixClassifier(sClassifier sc, Matrix avgcov);
+
 #define	EPS	(1.0e-6)	/* for singular matrix check */
 sClassifier
 sNewClassifier()
@@ -363,9 +366,7 @@ register Matrix sigma;
 	return result;
 }
 
-FixClassifier(sc, avgcov)
-register sClassifier sc;
-Matrix avgcov;
+static void FixClassifier(sClassifier sc, Matrix avgcov)
 {
 	int i;
 	double det;
