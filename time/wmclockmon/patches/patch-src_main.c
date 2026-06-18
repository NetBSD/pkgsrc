$NetBSD: patch-src_main.c,v 1.1 2026/06/18 19:50:48 nia Exp $

Include the correct header for bzero(3).

--- src/main.c.orig	2026-06-18 19:48:16.597599807 +0000
+++ src/main.c
@@ -37,6 +37,7 @@
 #include <dirent.h>
 #include <locale.h>
 #include <ctype.h>
+#include <strings.h>
 #include "dockapp.h"
 #include "backlightB_on.xpm"
 #include "backlightB_off.xpm"
