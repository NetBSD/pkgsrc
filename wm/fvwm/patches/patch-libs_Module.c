$NetBSD: patch-libs_Module.c,v 1.1 2026/03/16 11:33:12 nia Exp $

Include necessary headers for alloca.

--- libs/Module.c.orig	2026-03-16 11:12:24.277973746 +0000
+++ libs/Module.c
@@ -17,7 +17,11 @@
 ** Module.c: code for modules to communicate with fvwm
 */
 #include "config.h"
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include "libs/defaults.h"
 #include "Module.h"
