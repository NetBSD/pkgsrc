$NetBSD: patch-libAfterConf_WinList.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterConf/WinList.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/WinList.c
@@ -377,16 +377,16 @@ WinList_fs2config (ASModuleConfig * asmo
 
 					if (mystrncasecmp (ptr, "Click", 5) == 0)
 						ptr += 5;
-					if (isdigit (ptr[0])) {
+					if (isdigit ((unsigned char)ptr[0])) {
 						action_no = atoi (ptr);
 						if (action_no <= 0)
 							action_no = 1;
 						--action_no;
 						action_no %= MAX_MOUSE_BUTTONS;
 						i = 0;
-						while (!isspace (ptr[i]) && ptr[i])
+						while (!isspace ((unsigned char)ptr[i]) && ptr[i])
 							++i;
-						while (isspace (ptr[i]) && ptr[i])
+						while (isspace ((unsigned char)ptr[i]) && ptr[i])
 							++i;
 						ptr += i;
 					}
