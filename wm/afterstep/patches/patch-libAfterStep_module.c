$NetBSD: patch-libAfterStep_module.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterStep/module.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/module.c
@@ -435,7 +435,7 @@ ConnectAfterStep (send_data_type message
 				int k = 0;
 				int c = MyArgs.saved_argv[i][k];
 
-				while (isalnum (c) || c == '-' || c == '+' || c == '.' || c == '_')
+				while (isalnum ((unsigned char)c) || c == '-' || c == '+' || c == '.' || c == '_')
 					c = MyArgs.saved_argv[i][++k];
 				quote = (c != '\0');
 			}
