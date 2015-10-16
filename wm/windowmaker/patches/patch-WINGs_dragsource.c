$NetBSD: patch-WINGs_dragsource.c,v 1.1 2015/10/16 10:42:23 adam Exp $

--- WINGs/dragsource.c.orig	2015-08-11 18:41:14.000000000 +0000
+++ WINGs/dragsource.c
@@ -2,6 +2,8 @@
 #include "wconfig.h"
 #include "WINGsP.h"
 
+#include <X11/Xlib.h>
+#include <X11/Xutil.h>
 #include <X11/Xatom.h>
 #include <X11/cursorfont.h>
 #ifdef USE_XSHAPE
