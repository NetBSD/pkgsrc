$NetBSD: patch-src_afterstep_theme.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/afterstep/theme.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/theme.c
@@ -88,7 +88,7 @@ ASThemeFileType detect_theme_file_type (
 					int i;
 					type = AST_ThemeTar;
 					for (i = 0; i < 17 && buf[i] != '\0'; ++i)
-						if (!isprint (buf[i])) {
+						if (!isprint ((unsigned char)buf[i])) {
 							type = AST_ThemeBad;
 							break;
 						}
