$NetBSD: patch-xdprformat_xtmPrFormat.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Provide a declaration of exit()

--- xdprformat/xtmPrFormat.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdprformat/xtmPrFormat.c
@@ -37,6 +37,7 @@ static char SCCSID[] = "@(#) Module: xtm
 ----------------------------------------------------------------------------*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
