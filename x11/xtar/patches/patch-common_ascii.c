$NetBSD: patch-common_ascii.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- common/ascii.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/ascii.c
@@ -24,6 +24,7 @@
  */
 
 #include <stdio.h>  
+#include <string.h>
 #include <time.h>
 
 #include "cdefs.h"
