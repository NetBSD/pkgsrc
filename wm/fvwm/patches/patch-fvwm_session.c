$NetBSD: patch-fvwm_session.c,v 1.1 2026/03/16 11:33:12 nia Exp $

Include necessary headers for alloca.

--- fvwm/session.c.orig	2026-03-16 11:14:36.911089486 +0000
+++ fvwm/session.c
@@ -21,7 +21,11 @@
 
 #include "config.h"
 
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
+#include <stdlib.h>
 #ifdef HAVE_GETPWUID
 #include <pwd.h>
 #endif
