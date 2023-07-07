$NetBSD: patch-parser.c,v 1.1 2023/07/07 08:25:37 nia Exp $

Fix incompatible declaration of exit(3).

--- parser.c.orig	1999-01-25 16:13:46.000000000 +0000
+++ parser.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 
 #include "xbeats.h"
 
