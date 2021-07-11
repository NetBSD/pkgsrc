$NetBSD: patch-libAfterStep_font.c,v 1.2 2021/07/11 12:13:17 bsiegert Exp $

Use ctype.h correctly.

--- libAfterStep/font.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/font.c
@@ -49,11 +49,11 @@ Bool load_font (const char *name_in, MyF
 		while (ptr[i])
 			++i;
 		while (--i >= 0)
-			if (!isdigit (ptr[i]))
+			if (!isdigit ((unsigned char)ptr[i]))
 				break;
-		if ((isspace (ptr[i]) || ptr[i] == '-') && ptr[i + 1]) {
+		if ((isspace ((unsigned char)ptr[i]) || ptr[i] == '-') && ptr[i + 1]) {
 			font_size = atoi (&(ptr[i + 1]));
-			while (i > 0 && isspace (ptr[i - 1]))
+			while (i > 0 && isspace ((unsigned char)ptr[i - 1]))
 				--i;
 			clean_name = mystrndup (name, i);
 		}
