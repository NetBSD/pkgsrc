$NetBSD: patch-xtools_xitError.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Provide a declaration of exit()

--- xtools/xitError.c.orig	1995-02-18 14:11:29.000000000 +0000
+++ xtools/xitError.c
@@ -39,6 +39,7 @@ static char SCCSID[] = "@(#) Module: xit
 ----------------------------------------------------------------------------*/
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <X11/Intrinsic.h>
