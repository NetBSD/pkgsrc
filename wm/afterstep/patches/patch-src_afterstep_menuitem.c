$NetBSD: patch-src_afterstep_menuitem.c,v 1.1 2025/09/12 02:18:42 gutteridge Exp $

Need function prototype for XkbKeycodeToKeysym(3).

--- src/afterstep/menuitem.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/menuitem.c
@@ -53,6 +53,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include <X11/XKBlib.h>
+
 #include "dirtree.h"
 
 /***************************************************************************/
@@ -64,7 +66,7 @@ MenuData *FindPopup (const char *name, i
 
 	if (name == NULL) {
 		if (!quiet)
-			show_error ("Empty Popup name specifyed");
+			show_error ("Empty Popup name specified");
 		return md;
 	}
 
