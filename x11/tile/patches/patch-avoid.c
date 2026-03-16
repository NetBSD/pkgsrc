$NetBSD: patch-avoid.c,v 1.1 2026/03/16 13:54:37 nia Exp $

Fix implicit declaration of index(3).

--- avoid.c.orig	2026-03-16 13:39:01.958909128 +0000
+++ avoid.c
@@ -30,6 +30,7 @@
 #include <X11/Xutil.h>
 #include <X11/Intrinsic.h>
 #include <stdio.h>
+#include <strings.h>
 #include "tilerc.h"
 #include "tile.h"
 #include "avoid.h"
