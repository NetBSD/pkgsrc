$NetBSD: patch-subtitle2pgm.c,v 1.1 2026/03/22 13:08:42 nia Exp $

Fix implicit declaration of exit(3).

--- subtitle2pgm.c.orig	2026-03-22 12:44:20.679319196 +0000
+++ subtitle2pgm.c
@@ -18,6 +18,7 @@
 
 #include "spudec.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include <assert.h>
 #include <sys/types.h>
 #include <sys/stat.h>
