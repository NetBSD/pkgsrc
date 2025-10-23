$NetBSD: patch-libAfterStep_clientprops.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterStep/clientprops.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/clientprops.c
@@ -233,7 +233,7 @@ read_int_resource (XrmDatabase db, const
 				ptr++;
 			val = atoi (ptr);
 			while (*ptr)
-				if (!isdigit ((int)*ptr++))
+				if (!isdigit ((unsigned char)*ptr++))
 					break;
 			if (*ptr == '\0') {
 				*value = val;
