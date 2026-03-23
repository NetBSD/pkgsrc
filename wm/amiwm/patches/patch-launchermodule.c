$NetBSD: patch-launchermodule.c,v 1.1 2026/03/23 11:34:07 nia Exp $

Fix implicit function declarations.

--- launchermodule.c.orig	2026-03-23 11:14:11.590855946 +0000
+++ launchermodule.c
@@ -3,8 +3,10 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <X11/Xlib.h>
+#include <X11/Xresource.h>
 #include <X11/Xutil.h>
 #include "libami.h"
+#include "alloc.h"
 #include "drawinfo.h"
 
 char *progname;
