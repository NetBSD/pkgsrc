$NetBSD: patch-libs_Graphics.c,v 1.1 2026/03/16 11:33:12 nia Exp $

Include necessary headers for alloca.

--- libs/Graphics.c.orig	2026-03-15 22:46:49.591656018 +0000
+++ libs/Graphics.c
@@ -20,7 +20,11 @@
 #include "config.h"
 
 #include <X11/Xlib.h>
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
 
 #include "defaults.h"
