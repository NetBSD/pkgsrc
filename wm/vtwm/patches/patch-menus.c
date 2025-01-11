$NetBSD: patch-menus.c,v 1.1 2025/01/11 14:47:07 wiz Exp $

Add missing header.

--- menus.c.orig	2018-04-21 01:39:31.000000000 -0400
+++ menus.c	2025-01-09 09:15:07.326476249 -0500
@@ -39,6 +39,7 @@
 #include <X11/Xos.h>
 #ifndef NO_REGEX_SUPPORT
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <regex.h>
 #endif
 #include <stdlib.h>
