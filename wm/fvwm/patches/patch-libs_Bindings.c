$NetBSD: patch-libs_Bindings.c,v 1.1 2026/03/16 11:33:12 nia Exp $

Include necessary headers for alloca.

--- libs/Bindings.c.orig	2026-03-16 11:16:14.476378231 +0000
+++ libs/Bindings.c
@@ -15,7 +15,11 @@
 
 #include "config.h"
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 
 #include <X11/keysym.h>
 #include <X11/X.h>
