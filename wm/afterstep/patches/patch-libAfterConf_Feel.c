$NetBSD: patch-libAfterConf_Feel.c,v 1.2 2025/10/23 01:28:08 gutteridge Exp $

Need function prototype for XkbKeycodeToKeysym(3).
Use ctype.h correctly.

--- libAfterConf/Feel.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/Feel.c
@@ -20,6 +20,8 @@
 
 #define LOCAL_DEBUG
 
+#include <X11/XKBlib.h>
+
 #include "../configure.h"
 #include "../libAfterStep/asapp.h"
 #include "../libAfterStep/afterstep.h"
@@ -523,7 +525,7 @@ FeelConfig *ParseFeelOptions (const char
 			break;
 		case FEEL_Mouse_ID:
 			if (item.data.binding.sym)
-				if (isdigit ((int)item.data.binding.sym[0]) && pCurr->sub) {
+				if (isdigit ((unsigned char)item.data.binding.sym[0]) && pCurr->sub) {
 					int button_num = item.data.binding.sym[0] - '0';
 
 					if (button_num >= 0 && button_num <= MAX_MOUSE_BUTTONS
