$NetBSD: patch-src_afterstep_menus.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/menus.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/menus.c
@@ -1335,8 +1335,8 @@ void on_menu_keyboard_event (ASInternalW
 		} else if ((keysym >= XK_A && keysym <= XK_Z) ||	/* Only consider alphabetic */
 							 (keysym >= XK_a && keysym <= XK_z) || (keysym >= XK_0 && keysym <= XK_9)) {	/* ...or numeric keys     */
 			int i;
-			if (islower (keysym))
-				keysym = toupper (keysym);
+			if (islower ((unsigned char)keysym))
+				keysym = toupper ((unsigned char)keysym);
 			LOCAL_DEBUG_OUT ("processing keysym [%c]", (char)keysym);
 			/* Search menu for matching hotkey */
 			for (i = 0; i < menu->items_num; i++)
