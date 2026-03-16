$NetBSD: patch-fvwm_menustyle.c,v 1.1 2026/03/16 11:33:12 nia Exp $

Include necessary headers for alloca.

--- fvwm/menustyle.c.orig	2026-03-16 11:15:39.329401453 +0000
+++ fvwm/menustyle.c
@@ -17,7 +17,11 @@
 
 #include "config.h"
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <assert.h>
 #include <X11/keysym.h>
 
